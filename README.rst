Building
========

(Verified to work with Ubuntu 18.04 LTS)

.. code-block:: shell

  mkdir build
  cd build
  ../configure --disable-kvm --enable-debug --target-list="x86_64-linux-user"
  make