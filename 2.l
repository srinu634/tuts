%{
#include"y.tab.h"
%}


%%

"a" {return lp;}
"b" {return rp;}
.|[\n] {return 0 ;}

%%

