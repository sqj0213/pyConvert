from distutils.core import setup, Extension

module1 = Extension('pyConvert',
                    define_macros = [('MAJOR_VERSION', '1'),
                                     ('MINOR_VERSION', '0')],
                    include_dirs = ['/usr/include/ImageMagick/','/usr/include'],
                    libraries = ['MagickCore','MagickWand','boost_python'],
                    library_dirs = ['/usr/lib64','/usr/lib/'],
                    sources = ['pyConvert.cpp'])

setup(name = 'pyConvert',
    version = '1.1',
    author = 'sunshare',
    author_email = 'sqj0213@163.com',
    description='This is a ImageMagick convert python lib',
    ext_modules=[module1]
    )


"""
from distutils.core import setup, Extension

module1 = Extension('demo',
                    define_macros = [('MAJOR_VERSION', '1'),
                                     ('MINOR_VERSION', '0')],
                    include_dirs = ['/usr/local/include'],
                    libraries = ['tcl83'],
                    library_dirs = ['/usr/local/lib'],
                    sources = ['demo.c'])

setup (name = 'PackageName',
       version = '1.0',
       description = 'This is a demo package',
       author = 'Martin v. Loewis',
       author_email = 'martin@v.loewis.de',
       url = 'http://docs.python.org/extending/building',
       long_description = '''
This is really just a demo package.
''',
       ext_modules = [module1])
"""