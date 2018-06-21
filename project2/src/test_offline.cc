#include "PagelibPreprocessor.h"
int main(void)
{
    Configuration conf("../conf/my.conf");
    PagelibPreprocessor p(conf);
    p.doProcess();
    return 0;
}
