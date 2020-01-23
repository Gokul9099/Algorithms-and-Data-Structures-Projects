/*Algos Project 3
Gokul Nithin Kumar Rajakumar
801082252
*/

#include<iostream>
#include<fstream>

using namespace std;
int flag=0,v[100],vert,edges,G[100][100],tree=0,traverse=0,visiited[100];
void dijkstra(int startnode);
void BFS (int startnode);
void DFS (int startnode);
int cycle (int am[100][100],int G[100][100]);
int checkroot (int start);
int bipartite(int start);
int main()
{
    int H[100][100],am[100][100],i,j,n,c,start,a,b,ch;
    char ca;
    while(1){
        cout<<"\n1. Create a Directed Graph.";
        cout<<"\n2. Perform DFS Traversal. ";
        cout<<"\n3. Perform BFS Traversal. ";
        cout<<"\n4. Find Shortest Path. ";
        cout<<"\n5. Detect a Cycle. ";
        cout<<"\n6. Check if Graph a Bipartite. ";
        cout<<"\n7. Check if Graph a tree. ";
        cout<<"\n8. Exit.";
        cout<<"\nEnter your Choice: ";
        cin>>ch;
        if (cin.fail())
        {
            cin.clear();
            cin.sync();

        }
        switch(ch){
        case 1:
        {
        tree=1;
        cout<<"Enter No of Vertices: ";
        cin>>vert;
        if (cin.fail())
        {
            cout << "Invalid Entry....\n";
            cin.clear();
            cin.sync();
            tree=0;
            break;
        }
        cout<<"Enter No of Edges: ";
        cin>>edges;
        if(edges>vert*vert)
        {
            cout<<"\nNo of Edges is invalid....\n";
            tree=0;
            break;
        }
        if (cin.fail())
        {
            cout << "\nInvalid Entry....\n";
            cin.clear();
            cin.sync();
            tree=0;
            break;
        }
    for(i=0;i<vert;i++)
        for(j=0;j<vert;j++)
            {
                G[i][j]=0;
                H[i][j]=0;
                am[i][j]=0;
            }

    cout<<"\nS D W\n";
    for (int i = 0; i < edges; i++)
    {
        cin>>a>>b>>c;
        if(a>=vert || b>=vert || a<0 || b<0)
        {
        cout<<"\n Invalid Vertex...\n";
        tree=0;
        }
        if(c<0)
        {
        cout<<"\n Negative Weight....\n";
        tree=0;
        }

        if (cin.fail())
        {
            cout << "Invalid Entry....\n";
            cin.clear();
            cin.sync();
            tree=0;
            break;
        }
        G[a][b]=c;
        H[a][b]=c;
    }
    if(tree==0)
        break;
    cout<<"\nEnter the starting node:";
    cin>>start;
    if(start>=vert ||start<0)
    {
        cout<<"\n Invalid Starting Node...";
        tree=0;
    }
    if (cin.fail())
        {
            cout << "Invalid Entry....\n";
            cin.clear();
            cin.sync();
            tree=0;
        }
        break;
        }
    case 2:
        {
            if(tree!=1)
                {
                cout<<"\nEnter the Graph First...";
                cout<<"\nSelect your choice again...\n";continue;
                }
            else
                {
                    DFS(start);
                    cout<<"\nDFS Traversal:\n";
                    for(i=0;i<traverse;i++)
                    cout<<visiited[i]<<" ";

                }
                break;
        }
    case 3:
        {
            if(tree!=1)
                {
                cout<<"\nEnter the Graph First...";
                cout<<"\nSelect your choice again...\n";continue;
                }
            else
                {
                    BFS(start);
                        cout<<"\nBFS Traversal:\n";
                        for(i=0;i<traverse;i++)
                        cout<<visiited[i]<<" ";
                }
                break;
        }
    case 4:
    {
        if(tree!=1)
        {
           cout<<"\nEnter the Graph First...";
           cout<<"\nSelect your choice again...\n";continue;
        }
        else
            dijkstra(start);
            break;
    }
    case 5:
    {
    if(tree!=1)
        {
           cout<<"\nEnter the Graph First...";
           cout<<"\nSelect your choice again...\n";
           continue;
        }
        else{
    for(i=0;i<vert;i++)
        for(j=0;j<vert;j++)
            H[i][j]=G[i][j];
    int r;
    r=cycle(am,H);
    cout<<"\nr= "<<r;
    if(r==1)
        cout<<"\nCycle is formed";
    else
        cout<<"\nNo Cycle is formed";
        }
        break;
    }
    case 6:
    {
    if(tree!=1)
        {
           cout<<"\nEnter the Graph First...";
           cout<<"\nSelect your choice again...\n";continue;
        }
        else{
    int t2=bipartite(start);
    if(t2==1)
        cout<<"\nThe Graph is Bipartite\n";
    else
        cout<<"\nThe Graph is not Bipartite\n";
        }
        break;
    }
    case 7:
    {
    if(tree!=1)
        {
           cout<<"\nEnter the Graph First...";
           cout<<"\nSelect your choice again...\n";continue;
        }
        else{
for(i=0;i<vert;i++)
        for(j=0;j<vert;j++)
            H[i][j]=G[i][j];
    int b=cycle(am,H);
    if(b==1)
        cout<<"\nCycle is formed\n";
    else
        cout<<"\nNo Cycle is formed\n";
    int s=checkroot(start);
    if(s==1)
        cout<<"\nSource node is the root for this graph";
    else
        cout<<"\nSource node is not the root for this graph";
    DFS(start);
    int t;

    if(traverse==vert)
        t=1;
    else t=0;
    if(t==1)
        cout<<"\nSource Node can traverse through all the nodes";
    else
        cout<<"\nSource Node cannot traverse through all the nodes";
    cout<<"\ns= "<<s<<"\nb= "<<b<<"\nt= "<<t;
    if(s==1 && b==0 && t==1)
        cout<<"\nHence the Graph is a tree.";
    else
        cout<<"\nHence the Graph is not a tree.";
        }
        break;
    }
    case 8:
        return 0;
    default:
        cout<<"\nInvalid Choice....\n";
    }
    }
    return 0;
}

int check(int visited[100],int j,int c)
{
    int flag=0;
    for(int i=0;i<c;i++)
    {
        if(visited[i]==j)
            {
                flag=1;
                break;
            }
    }
    if(flag==0)
        return 0;
    else
        return 1;
}

void BFS (int startnode)
{
    int visited[100],i,j=0,a=0,c=0,pointer=0,n=vert;
    visited[c++]=startnode;
    if(vert==1)
        traverse=c;
    while(pointer<n)
    {
        if(G[startnode][j]>0 && j<n)
        {
            a=check(visited,j,c);
            if(a==0)
            {
                visited[c++]=j++;
                traverse=c;
            }
            else
                j++;
        }
        else
            j++;
        if(j==n)
        {
            startnode=visited[pointer++];
            if(pointer>c)
                break;
            j=0;
        }
    }
    for(i=0;i<c;i++)
        visiited[i]=visited[i];
}

void DFS (int startnode)
{
    int lastvisited[100],visited[100],j=0,i,a=0,c=0,pointer=0,n=vert;
    visited[c++]=startnode;
traverse=c;

    //cout<<j<<" ";
                //cout<<"\nstartnode= "<<startnode;
                //cout<<"\npointer= "<<pointer;
    while(c<n){
        if(G[startnode][j]>0)
        {

            a=check(visited,j,c);
            if(a==0)
            {
                visited[c++]=j;
                traverse=c;
                //cout<<j<<" ";
                lastvisited[startnode]=j;
                startnode=j;
                pointer+=1;
                //cout<<"\nstartnode= "<<startnode;
                //cout<<"\npointer= "<<pointer;
                j=0;
            }
            else
                j++;
        }
        else
            j++;
        if(j==n)
        {
            startnode=visited[--pointer];
            if(pointer<0)
                break;
            j=lastvisited[startnode];
        }
    }
    for(i=0;i<c;i++)
        visiited[i]=visited[i];
}

struct node_info
{
    int no;
}*q = NULL, *r = NULL;
struct node
{
    node_info *pt;
    node *next;
}*top = NULL, *p = NULL, *np = NULL;
void push(node_info *ptr)
{
    np = new node;
    np->pt = ptr;
    np->next = NULL;
    if (top == NULL)
    {
        top = np;
    }
    else
    {
        np->next = top;
        top = np;
    }
}
node_info *pop()
{
    if (top == NULL)
    {
        cout<<"underflow\n";
    }
    else
    {
        p = top;
        top = top->next;
        return(p->pt);
        delete(p);
    }
}
int back_edges(int *v,int am[100][100],int i,int k)
{
    q = new node_info;
    q->no = i;
    push(q);
    v[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (am[i][j] == 1 && v[j] == 0)
        {
            back_edges(v, am, j, i);
        }
        else if (am[i][j] == 0)
            continue;
        else if ((j == k) && (am[i][k] == 1 && v[j] == 1))
            continue;
        else
        {
            flag = -1;
        }
    }
    r = pop();
    return(flag);
}
void init()
{
    for (int i = 0; i < vert; i++)
        v[i] = 0;
    while (top != NULL)
    {
        pop();
    }
}
int cycle(int am[100][100], int wm[100][100])
{
    int ve = 1, min, temp, temp1,a,b,x;
    for(int i=0;i<vert;i++)
    {
        for(int j=0;j<vert;j++)
        {
            if(wm[i][j]>0 && wm [j][i]>0)
                return 1;
        }
    }
    while (x<100)
    {
        min =999,temp=0,temp1=0,x++;
        for(int i=0;i<vert;i++)
        {
            for(int j=0;j<vert;j++)
            {
                if ((wm[i][j] < min) && wm[i][j]!=0)
                {
                    min = wm[i][j];
                    temp = i;
                    temp1 = j;
                }
                else if (wm[i][j] == 0)
                    continue;
            }
        }
        a=wm[temp][temp1];
        wm[temp][temp1]=wm[temp1][temp] = 999;
        am[temp][temp1]=am[temp1][temp] = 1;
        init();
        if (back_edges(v, am, temp, 0) < 0)
        {
            am[temp][temp1]=am[temp1][temp] = 0;
            flag = 0;
            return 1;
        }
        else
            ve++;
    }
    return 0;
}


int checkroot(int start)
{
    int i=0,j=start;
    if(vert==1 && edges==0)
    return 1;
    while(1){
        if(G[i][j]>0){
            return 0;
        }
        else
            i++;
        if(i==vert-1)
            return 1;
    }

    return 0;
}



int bipartite(int startnode)
{
    int visited[100],k,colour[100],f,i,j=0,a=0,c=0,pointer=0,n=vert,flag=1;
    for(k=0;k<vert;k++)
    {
        if(G[k][k]>0)
            return 0;
    }
    DFS(startnode);
    if(traverse==1)
        return 1;
    colour[startnode]=flag;
    //cout<<"\ncolour[startnode]= "<<colour[startnode];
    visited[c++]=startnode;
    flag=2;
    while(pointer<n)
    {

        if(G[startnode][j]>0 && j<n)
        {
            a=check(visited,j,c);
            if(a==0)
            {
                //cout<<"\nstartnode= "<<startnode;
                //cout<<"\nj= "<<j;

                colour[j]=flag;
                //cout<<"\ncolour["<<j<<"]= "<<colour[j];
                visited[c++]=j++;
            }
            else
            {

                if(colour[j]==colour[startnode])
                    return 0;
                j++;
            }
        }
        else
            j++;
        if(j==n)
        {
            //cout<<"\nstartnode= "<<startnode;
                //cout<<"\nj= "<<j;
                startnode=visited[++pointer];
            j=0;
            if(flag==1)
                flag=2;
            else
                flag=1;
            //cout<<"\n Flag= "<<flag;
        }
    }
     return 1;
}


void dijkstra(int startnode)
{

    int cost[100][100],distance[100],pred[100],n=vert;
    int visited[100],count,mindistance,nextnode,i,j;

    //pred[] stores the predecessor of each node
    //count gives the number of nodes seen so far
    //create the cost matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(G[i][j]==0)
                cost[i][j]=9999;
            else
                cost[i][j]=G[i][j];

    //initialize pred[],distance[] and visited[]
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }

    distance[startnode]=0;
    visited[startnode]=1;
    count=1;

    while(count<n-1)
    {
        mindistance=9999;

        //next node gives the node at minimum distance
        for(i=0;i<n;i++)
            if(distance[i]<mindistance&&!visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }

            //check if a better path exists through next node
            visited[nextnode]=1;
            for(i=0;i<n;i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
        count++;
    }

    //print the path and distance of each node
    for(i=0;i<n;i++)
        if(i!=startnode)
        {
            if(distance[i]==9999)
                cout<<"\nDistance of node "<<i<<"= "<<"INF";
            else
                cout<<"\nDistance of node "<<i<<"= "<<distance[i];
            cout<<"\nPath= "<<i;
            j=i;
            do
            {
                j=pred[j];
                cout<<"<-"<<j;
            }while(j!=startnode);
    }
}
