clean :
	rm -f run test hack PromoteDrafts.md && touch PromoteDrafts.md
clearAllCodeFile :
	make clean && rm -f code.c test.c run.c
initCode :
	make clearAllCodeFile && touch code.c 
initFun :
	initCode && touch run.c && touch test.c
	