#pragma once

enum EXCEPTION_CODE
{
	openError,
	readError,
	lackOfMemory,
	notNaturalNumber
};


/*Wy�wietla zaistnia�e wyj�tki*/
void seeExceptions(EXCEPTION_CODE error);
