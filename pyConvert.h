/* 
 * File:   pythonConvert.h
 * Author: root
 *
 * Created on November 5, 2012, 9:34 PM
 */

#ifndef PYTHONCONVERT_H
#define	PYTHONCONVERT_H
#define MAX_ARGS_COUNT	100
#ifdef	__cplusplus
extern "C" {
#endif

	char *g_argc1[MAX_ARGS_COUNT] = {0};
	int g_argv1 = 0;
	int ConvertMain(int argc,char **argv);


#ifdef	__cplusplus
}
#endif

#endif	/* PYTHONCONVERT_H */

