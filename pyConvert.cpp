#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "wand/MagickWand.h"
#if defined(__WINDOWS__)
#include <windows.h>
#endif


#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include "pyConvert.h"
/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                             %
%                                                                             %
%                                                                             %
%  M a i n                                                                    %
%                                                                             %
%                                                                             %
%                                                                             %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%
*/
int ConvertMain(int argc,char **argv)
{

  char
    *option;

  double
    elapsed_time,
    user_time;

  ExceptionInfo
    *exception;

  ImageInfo
    *image_info;

  MagickBooleanType
    regard_warnings,
    status;

  register long
    i;

  TimerInfo
    timer;

  unsigned long
    iterations;

  MagickCoreGenesis(*argv,MagickTrue);
  exception=AcquireExceptionInfo();
  iterations=1;
  status=MagickFalse;
  regard_warnings=MagickFalse;
  	

  for (i=1; i < (long) (argc-1); i++)
  {
    option=argv[i];
    if ((strlen(option) == 1) || ((*option != '-') && (*option != '+')))
      continue;
    if (LocaleCompare("bench",option+1) == 0)
      iterations=(unsigned long) atol(argv[++i]);
    if (LocaleCompare("debug",option+1) == 0)
      (void) SetLogEventMask(argv[++i]);
    if (LocaleCompare("regard-warnings",option+1) == 0)
      regard_warnings=MagickTrue;
  }
  	
  GetTimerInfo(&timer);
  	
  for (i=0; i < (long) iterations; i++)
  {
    image_info=AcquireImageInfo();
  	
    status=ConvertImageCommand(image_info,argc,argv,(char **) NULL,exception);
  	
    if (exception->severity != UndefinedException)
      {
  	
        if ((exception->severity > ErrorException) ||
            (regard_warnings != MagickFalse))
          status=MagickTrue;
  	
        CatchException(exception);
  	
      }
  	
    image_info=DestroyImageInfo(image_info);
  	
  }
	
  if (iterations > 1)
    {
      elapsed_time=GetElapsedTime(&timer);
      user_time=GetUserTime(&timer);
      (void) fprintf(stderr,"Performance: %lui %gips %0.3fu %ld:%02ld\n",
        iterations,1.0*iterations/elapsed_time,user_time,(long)
        (elapsed_time/60.0+0.5),(long) ceil(fmod(elapsed_time,60.0)));
    }
 	
 exception=DestroyExceptionInfo(exception);
  MagickCoreTerminus();
	
  return(status == MagickFalse ? 0 : 1);
}


/*
g++ -fPIC -c ./pythonConvert.c   -I ./openSrc/ImageMagick-6.5.4-10/
 g++ -fPIC  -c  ./pyConvert.c  -I ../ -I ./openSrc/ImageMagick-6.5.4-10/ -I /usr/include/python2.6/ -lMagickWand -L ../wand/.libs/libMagickWand.so -lboost_python -L ./boost_1_52_0/stage/lib/libboost_python.so -lxml2  -lm -lpthread -ldl -lgomp
g++ -shared  -fPIC -o pyConvert.so -g  ./pyConvert.c pythonConvert.o -I ../ -I ./openSrc/ImageMagick-6.5.4-10/ -I /usr/include/python2.6/ -lMagickWand -L ../wand/.libs/libMagickWand.so -lboost_python -L ./boost_1_52_0/stage/lib/libboost_python.so -lxml2  -lm -lpthread -ldl -lgomp

g++ -shared -fPIC -o pyConvert.so ./pyConvert.c -I ./openSrc/ImageMagick-6.5.4-10/ -lMagickCore -lMagickWand -lboost_python -I /usr/include/python2.6/
*/

int pyList(boost::python::list listValue )
{
	extern char *g_argc1[MAX_ARGS_COUNT];
    extern int g_argv1;
	g_argv1 = 0;
	g_argv1 = boost::python::call_method<int>(listValue.ptr(), "__len__" );
	int  i;
	for ( i = 0; i < g_argv1; i++ )
	{
                g_argc1[ i ] = boost::python::call_method<char*>(listValue.ptr(), "__getitem__", i);
	}

	return ConvertMain( g_argv1, g_argc1 );

}
using namespace boost;
BOOST_PYTHON_MODULE(pyConvert)
{	
    namespace bpy = boost::python;
    bpy::def("pyConvert", pyList);
}


#if defined(__MAIN__)

int main( int argv, char **argc )
{
	return ConvertMain( argv, argc );
}
#endif

