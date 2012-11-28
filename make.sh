rm -f ./*.so
rm -f ./*.o
rm -f ./pyConvert
rm -f ./pyConvert.so
g++ -shared -fPIC -o pyConvert.so ./pyConvert.cpp  -I ./ -I/usr/include/ImageMagick/ -I /usr/include/python2.6/ -lboost_python -lMagickWand -lMagickCore
g++ -D__MAIN__=1 -fPIC -o pyConvert ./pyConvert.cpp  -I ./ -I/usr/include/ImageMagick/ -I /usr/include/python2.6/ -lboost_python -lMagickWand -lMagickCore

ldd ./pyConvert.so
python ./test.py