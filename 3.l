%{
#include"y.tab.h"
int flag = 0;
%}


%%

"a" {flag ++; return lp;}
"b" {return rp;}
.|[\n] {return 0 ;}

%%

