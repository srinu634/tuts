%{
#include"y.tab.h"
%}


%%

"(" {return lp;}
")" {return rp;}
.|[\n] {return 0 ;}

%%

