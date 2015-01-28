// -------------------------------------------------------------
/*
 *     Copyright (c) 2013 Battelle Memorial Institute
 *     Licensed under modified BSD License. A copy of this license can be found
 *     in the LICENSE file in the top level directory of this distribution.
 */
// -------------------------------------------------------------
/**
 * @file   implementation_visitor.cpp
 * @author William A. Perkins
 * @date   2015-01-28 10:21:26 d3g096
 * 
 * @brief  
 * 
 * 
 */

// -------------------------------------------------------------


#include <boost/assert.hpp>
#include "implementation_visitor.hpp"

namespace gridpack {
namespace math {

// -------------------------------------------------------------
//  class ImplementationVisitor
// -------------------------------------------------------------

// -------------------------------------------------------------
// ImplementationVisitor:: constructors / destructor
// -------------------------------------------------------------
ImplementationVisitor::ImplementationVisitor()
  : utility::Uncopyable()
{
}

ImplementationVisitor::~ImplementationVisitor(void)
{
}

// -------------------------------------------------------------
// ImplementationVisitor::visit
// -------------------------------------------------------------
void 
ImplementationVisitor::visit(PetscVectorWrapper&)
{
  BOOST_ASSERT(false);
}

void 
ImplementationVisitor::visit(PetscMatrixWrapper&)
{
  BOOST_ASSERT(false);
}

void 
ImplementationVisitor::visit(MatrixImplementation&)
{
  BOOST_ASSERT(false);
}

void 
ImplementationVisitor::visit(PETScMatrixImplementation&)
{
  BOOST_ASSERT(false);
}

void 
ImplementationVisitor::visit(LinearSolverImplementation&)
{
  BOOST_ASSERT(false);
}

void 
ImplementationVisitor::visit(PETScLinearSolverImplementation&)
{
  BOOST_ASSERT(false);
}

// -------------------------------------------------------------
//  class ConstImplementationVisitor
// -------------------------------------------------------------

// -------------------------------------------------------------
// ConstImplementationVisitor:: constructors / destructor
// -------------------------------------------------------------
ConstImplementationVisitor::ConstImplementationVisitor()
  : utility::Uncopyable()
{
}

ConstImplementationVisitor::~ConstImplementationVisitor(void)
{
}

// -------------------------------------------------------------
// ConstImplementationVisitor::visit
// -------------------------------------------------------------
void 
ConstImplementationVisitor::visit(const PetscVectorWrapper&)
{
  BOOST_ASSERT(false);
}

void 
ConstImplementationVisitor::visit(const PetscMatrixWrapper&)
{
  BOOST_ASSERT(false);
}

void 
ConstImplementationVisitor::visit(const MatrixImplementation&)
{
  BOOST_ASSERT(false);
}

void 
ConstImplementationVisitor::visit(const PETScMatrixImplementation&)
{
  BOOST_ASSERT(false);
}

void 
ConstImplementationVisitor::visit(const LinearSolverImplementation&)
{
  BOOST_ASSERT(false);
}

void 
ConstImplementationVisitor::visit(const PETScLinearSolverImplementation&)
{
  BOOST_ASSERT(false);
}


} // namespace math
} // namespace gridpack

