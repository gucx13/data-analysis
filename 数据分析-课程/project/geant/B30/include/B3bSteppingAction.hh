//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: B4aSteppingAction.hh 68058 2013-03-13 14:47:43Z gcosmo $
// 
/// \file B4aSteppingAction.hh
/// \brief Definition of the B4aSteppingAction class

#ifndef B3bSteppingAction_h
#define B3bSteppingAction_h 1

#include "G4UserSteppingAction.hh"

#if 0
extern bool bUnder;
extern bool bUpper;
#endif

class B3DetectorConstruction;
class B3bEventAction;

/// Stepping action class.
///
/// In UserSteppingAction() there are collected the energy deposit and track 
/// lengths of charged particles in Absober and Gap layers and
/// updated in B4aEventAction.

class B3bSteppingAction : public G4UserSteppingAction
{
public:
  B3bSteppingAction(const B3DetectorConstruction* detectorConstruction,
                    B3bEventAction* eventAction);
  virtual ~B3bSteppingAction();

  virtual void UserSteppingAction(const G4Step* step);
    
private:
  const B3DetectorConstruction* fDetConstruction;
  B3bEventAction*  fEventAction;  
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
