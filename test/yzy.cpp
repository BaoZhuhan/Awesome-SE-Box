下列代码的功能是对一个给定的图G执行拓扑排序，其中TopNum[]从1开始记录拓扑序。

void Topsort( Graph G )
{
   Queue Q;
   Vertex V, W;
   NodePtr ptr;
   int counter = 0;

   Q = CreateEmptyQueue(NumVertex);
   for ( V=0; V<G->NumV; V++ )
      if ( Indegree[V] == 0 )
         Enqueue(V, Q);
   while ( !IsEmpty(Q) ){
      V = Dequeue( Q );
      TopNum[V] = 
3 分
;
      for ( ptr=G->List[V]; ptr; ptr=ptr->Next) {
         W = ptr->Vertex;
         if ( 
3 分
 == 0 )
            Enqueue(W, Q);
      }
   }
   if ( counter != NumVertex )
      printf("ERROR: Graph has a cycle.\n");
   DisposeQueue(Q);
}