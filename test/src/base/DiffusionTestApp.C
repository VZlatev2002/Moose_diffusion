//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "DiffusionTestApp.h"
#include "DiffusionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
DiffusionTestApp::validParams()
{
  InputParameters params = DiffusionApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

DiffusionTestApp::DiffusionTestApp(InputParameters parameters) : MooseApp(parameters)
{
  DiffusionTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

DiffusionTestApp::~DiffusionTestApp() {}

void
DiffusionTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  DiffusionApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"DiffusionTestApp"});
    Registry::registerActionsTo(af, {"DiffusionTestApp"});
  }
}

void
DiffusionTestApp::registerApps()
{
  registerApp(DiffusionApp);
  registerApp(DiffusionTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
DiffusionTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  DiffusionTestApp::registerAll(f, af, s);
}
extern "C" void
DiffusionTestApp__registerApps()
{
  DiffusionTestApp::registerApps();
}
