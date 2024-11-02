clean :
	rm -f run test hack PromoteDrafts.md && touch PromoteDrafts.md
saveAllCodeFile :
	mkdir lastVersion && cp code.c lastVersion && cp run.c lastVersion && cp test.c lastVersion
clearAllCodeFile :
	make clean && rm -f code.c test.c run.c
initCode :
	make saveAllCodeFile && make clearAllCodeFile && touch code.c 
initFun :
	initCode && touch run.c && touch test.c
	