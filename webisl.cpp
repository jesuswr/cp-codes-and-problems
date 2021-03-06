#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int maxN = 100005;
int v, e;

int visited[maxN];
int comp[maxN];
stack<int> st;
vector<int> graph[maxN];
vector<int> graphT[maxN];


void dfs1(int x)
{
	visited[x] = 1;

	for (int y: graph[x])
	{
		if ( !visited[y] ) dfs1(y);
	}

	st.push(x);
}


void dfs2(int x)
{
	visited[x] = 2;

	for (int y: graphT[x])
	{
		if ( visited[y] == 1)
		{
			comp[y] = comp[x];
			dfs2(y);
		}
	}
}

void kosaraju()
{
	for (int i = 0; i < v; ++i)
	{
		if ( !visited[i] ) dfs1(i);
	}

	int cont = 0;
	int aux;

	while( !st.empty() ) 
	{
	    aux = st.top();
	    st.pop();

	    if ( visited[aux] == 1 )
	    {
	    	comp[aux] = cont;
	    	dfs2(aux);
	    	cont ++;
	    }
	}
}



int main()
{
	scanf("%d %d", &v, &e);

	int n1, n2;
	for (int i = 0; i < e; ++i)
	{
		scanf("%d %d", &n1, &n2);
		graph[n1].push_back(n2);
		graphT[n2].push_back(n1);
	}

	kosaraju();

	int currentComp;

	for (int i = 0; i < v; ++i)
	{
		currentComp = comp[i];
		for (int j = 0; j <= i; ++j)
		{
			if ( currentComp == comp[j])
			{
				currentComp = j;
				break;
			} 
		}
		printf("%d\n", currentComp);
	}

}