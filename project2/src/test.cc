#include "Pagelib.h"
int main(void)
{
    DirScanner dirs("../data/rss");
    Pagelib page(dirs);
    page.create();
    page.store_pagelib("../data/page_lib.dat");
    page.store_offsetlib("../data/offset_lib.dat");
    return 0;
}
