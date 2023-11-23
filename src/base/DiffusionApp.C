#include "DiffusionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
DiffusionApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

DiffusionApp::DiffusionApp(InputParameters parameters) : MooseApp(parameters)
{
  DiffusionApp::registerAll(_factory, _action_factory, _syntax);
}

DiffusionApp::~DiffusionApp() {}

void 
DiffusionApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<DiffusionApp>(f, af, s);
  Registry::registerObjectsTo(f, {"DiffusionApp"});
  Registry::registerActionsTo(af, {"DiffusionApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
DiffusionApp::registerApps()
{
  registerApp(DiffusionApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
DiffusionApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  DiffusionApp::registerAll(f, af, s);
}
extern "C" void
DiffusionApp__registerApps()
{
  DiffusionApp::registerApps();
}
