from setuptools import setup
from setuptools.extension import Extension

def main():
    setup(name="cwhois",
          version="1.0.0",
          description="Python interface for executing rfc1036 whois",
          author="Mariusz Krzyzok, Marco d'Itri",
          url="http://github.com/damemay/cwhois/",
          license="GPL-2.0",
          ext_modules=[Extension(
              "cwhois",
              sources=['utils.c', 'whois.c'],
              include_dirs=['.'],
              runtime_library_dirs=['.'],
              extra_link_args=["-lidn2"], 
              extra_compile_args=["-DHAVE_LIBIDN2", "-DHAVE_CRYPT_H", "-DHAVE_LINUX_CRYPT_GENSALT"])],
          # packages=["cwhois"],
          keywords=["whois", "tld", "domain", "registrar",],
          python_requires=">=3.5",
          platforms="All")

if __name__ == "__main__":
    main()
