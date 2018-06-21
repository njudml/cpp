#include "Pagelib.h"
#include <fstream>
#include <set>
Pagelib::Pagelib(DirScanner& dirScanner)
    : _dirScanner(dirScanner)
{
}

void Pagelib::process(const string& filename)
{
    using namespace tinyxml2;

    XMLDocument doc;
    doc.LoadFile(filename.c_str());
    XMLElement* proot = doc.FirstChildElement("rss");
    XMLElement* pchannel = proot->FirstChildElement("channel");
    XMLElement* pitem = pchannel->FirstChildElement("item");
    while (pitem) {
        XMLElement* ptitle = pitem->FirstChildElement("title");
        XMLElement* plink = pitem->FirstChildElement("link");
        XMLElement* pdescription = pitem->FirstChildElement("description");
        XMLElement* pcontent = pitem->FirstChildElement("content:encoded");

        string title;
        string url;
        string description;
        string content;
        if (ptitle)
            title = string(ptitle->GetText());
        if (plink)
            url = string(plink->GetText());
        if (pdescription)
            description = string(pdescription->GetText());
        if (pcontent)
            content = string(pcontent->GetText());
        else
            content=string(pdescription->GetText());

        boost::regex re("<.+?>");

        content=boost::regex_replace(content, re, string());

        int docid = _files.size();
        string txt = "<doc><docid>" + to_string(++docid) + "</docid><url>" + url + "</url><title>" + title + "</title><content>" + content + "</content></doc>";
        

        _files.push_back(txt);

        pitem = pitem->NextSiblingElement();
    }
}

void Pagelib::create()
{
    set<string> filesname = _dirScanner.getFiles();
    for (auto fname : filesname) {
        process(fname);
        cout << fname << endl;
    }
    cout << "what's happen" << endl;
}

void Pagelib::store_pagelib(const string& filepath)
{
    cout << "hello" << endl;
    ofstream ofs(filepath);
    int docid, offset, len;
    docid = 0;
    for (auto txt : _files) {

        ++docid;
        offset = ofs.tellp();
        cout << "offect= " << offset;
        len = txt.size();
        cout << "len= " << len << endl;
        ofs << txt << endl;
        _offsetlib[docid] = make_pair(offset, len);
    }
    ofs.close();
}

void Pagelib::store_offsetlib(const string& filepath)
{
    ofstream ofs(filepath);
    for (auto each : _offsetlib)
        ofs << each.first << "\t" << each.second.first << "\t" << each.second.second << endl;
    ofs.close();
}
