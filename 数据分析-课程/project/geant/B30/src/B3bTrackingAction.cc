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
// $Id: B3bRunAction.cc 94031 2015-11-05 11:54:38Z ihrivnac $
//
/// \file B3bRunAction.cc
/// \brief Implementation of the B3bRunAction class

#include "B3bRunAction.hh"
#include "B3bRun.hh"
#include "B3PrimaryGeneratorAction.hh"
#include "B3Analysis.hh"
#include "B3bEventAction.hh"
#include "B3bTrackingAction.hh"



#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4EventManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4TrackingManager.hh"
#include "G4Track.hh"

#include "B3Analysis.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
#if 1
B3bTrackingAction::B3bTrackingAction(B3bEventAction* eventAction)
 :  G4UserTrackingAction(),
    fEventAction(eventAction)	
{
    
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B3bTrackingAction::~B3bTrackingAction()
{
}
#endif

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#if 0
void B3bTrackingAction::PostUserTrackingAction(const G4Track* track){
	
}
#endif

void B3bTrackingAction::BeginOfTrackingAction(const G4Track* track)
{ 


  //G4cout << "### Run " << run->GetRunID() << " start." << G4endl;
  //inform the runManager to save random number seed
  //G4RunManager::GetRunManager()->SetRandomNumberStore(false);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B3bTrackingAction::EndOfTrackingAction(const G4Track* track)
{
#if 0
	G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

	//G4String fuhe = "anti_nu_e";


	if(track->GetDefinition()->GetParticleName()=="anti_nu_e"){
		auto first = track->GetTrackID();
      		auto ene = track->GetTotalEnergy();
		G4cout<<"I find it !!!!!!!!!!!!!!!!!!!!!!!"<<G4endl;
		analysisManager->FillNtupleDColumn(1, 0, first);
		analysisManager->FillNtupleDColumn(1, 1, ene);
	
		analysisManager->AddNtupleRow(1);	
	}
	
	fEventAction->nu_E = track->GetGlobalTime() ;


	//auto x = track->GetPosition();
//	}
#endif

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
