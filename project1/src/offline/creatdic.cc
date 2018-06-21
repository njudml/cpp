#include "DicProducer.h"
#include "zhSplitTool.h"
#include "enSplitTool.h"
int main(void)
{
    DicProducer dic("../../data/art",new ZhSplitTool()); 
    printf("hello\n");
    dic.build_dict("../../data/stop_words_zh.txt"); 
    dic.store_dict("../../data/dict_zh.dat");
    return 0;
}
