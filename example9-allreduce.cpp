/*
 * Adapted from
 * http://www.boost.org/doc/libs/1_59_0/doc/html/mpi/tutorial.html
 *
 * Created by Misaka-10032 (longqic@andrew.cmu.edu) on 10/15/15.
 *
 * Another version of all_reduce.
 */

#include <boost/mpi.hpp>
#include <iostream>
#include <cstdlib>
namespace mpi = boost::mpi;

int main(int argc, char* argv[])
{
  mpi::environment env(argc, argv);
  mpi::communicator world;

  std::srand(world.rank());
  int my_number = std::rand();

  all_reduce(world, my_number, mpi::minimum<int>());

  if (world.rank() == 0) {
    std::cout << "The minimum value is " << my_number << std::endl;
  }

  return 0;
}
