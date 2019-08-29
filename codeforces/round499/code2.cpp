
void dfs2(int v)
{
    if(g[v].change==false)
        for(int i=0;i<g[v].in.size();i++)
            g[g[v].in[i]].change=false;
    else
        switch(g[v].type)
        {
        case 'A':
            if(g[v].val == (!g[g[v].in[0]].val) & g[g[v].in[1]].val){
                g[g[v].in[0]].change = false;
            }
            else{
                g[g[v].in[0]].change = true;
            }
            if(g[v].val == (g[g[v].in[0]].val & !g[g[v].in[1]].val)){
                g[g[v].in[1]].change = false;
            }
            else{
                g[g[v].in[1]].change = true;
            }
            break;
        case 'O':
            if(g[v].val == (!g[g[v].in[0]].val) | g[g[v].in[1]].val){
                g[g[v].in[0]].change = false;
            }else{
                g[g[v].in[0]].change = true;
            }
            if(g[v].val == (g[g[v].in[0]].val | !g[g[v].in[1]].val)){
                g[g[v].in[1]].change = false;
            }else{
                g[g[v].in[1]].change = true;
            }
            break;
        case 'X':
            if(g[v].val == (!g[g[v].in[0]].val) ^ g[g[v].in[1]].val){
                g[g[v].in[0]].change = false;
            }else{
                g[g[v].in[0]].change = true;
            }
            if(g[v].val == (g[g[v].in[0]].val ^ !g[g[v].in[1]].val)){
                g[g[v].in[1]].change = false;
            }else{
                g[g[v].in[1]].change = true;
            }
            break;
        case 'N':
            if(g[v].val == (!!g[g[v].in[0]].val)){
                g[g[v].in[0]].change = false;
            }else{
                g[g[v].in[0]].change = true;
            }
            break;
        }
    
    for(int i = 0; i < g[v].in.size(); ++i)
        dfs2(g[v].in[i]);
}