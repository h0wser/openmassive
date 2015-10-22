# OpenMassive [![Build Status](https://magnum.travis-ci.com/Deoxyribonucleic/openmassive.svg?token=ihnsZhoM8Qtss7yAhAhE)](https://magnum.travis-ci.com/Deoxyribonucleic/openmassive)

**OpenMassive** (working title) is an application framework for massive,
scalable applications such as MMOs.


## Libraries

**[util](https://github.com/Deoxyribonucleic/openmassive/wiki/om::util)** -
a library containing facilities for logging, event handling,
task scheduling and data serialization. Useful for every type of application.

**[comm](https://github.com/Deoxyribonucleic/openmassive/wiki/om::comm)** -
communications library.

**[arch](https://github.com/Deoxyribonucleic/openmassive/wiki/om::arch)** -
generic scalable application architecture library.

**[game](https://github.com/Deoxyribonucleic/openmassive/wiki/om::game)** -
contains facilities specifically designed for MMOs, such as a login server,
proxy servers, and world servers. 


## Coding style
Ident using tabs, align using spaces. In general, try to mimic the style of
existing code.

The naming convention is as follows:
* MyClass
* myObject
* myFunction
* m\_myMember
* MY\_CONSTANT
* mynamespace

General rules of thumb:
* Keep variable scope as small as possible.
* Keep functions and classes as small as possible.
* Avoid global state (this includes singletons). The exception here is the
logging facility, for convenience.


## License
OpenMassive is licensed under the [MIT license](LICENSE).

