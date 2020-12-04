'''
To run this you have to do install via `python3 setup.py install`
'''

from distutils.core import setup, Extension

def main():
    setup(name="fputs",
          version="1.0.0",
          description="Python interface for the fputs C library function",
          author="Al-Baraa El-Hag",
          author_email="a.elhag01@gmail.com",
          ext_modules=[Extension("fputs", ["fputsmodule.c"])])

if __name__ == "__main__":
    main()
