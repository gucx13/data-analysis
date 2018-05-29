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

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

//#include "TFile.h"
//#include "TTree.h"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B3bRunAction::B3bRunAction()
 : G4UserRunAction()
{ 

  // set printing event number per each event 
  G4RunManager::GetRunManager()->SetPrintProgress(1);

  auto analysisManager = G4AnalysisManager::Instance();
  G4cout << "Using " << analysisManager->GetType() << G4endl;  

  analysisManager->SetVerboseLevel(2);
//  analysisManager->SetNtupleMerging(true);

  analysisManager->SetFirstHistoId(1);


  analysisManager->CreateNtuple("sig", "Energy");
  analysisManager->CreateNtupleDColumn(0,"EventID"); 
  analysisManager->CreateNtupleDColumn(0,"E_nu"); 
  analysisManager->FinishNtuple(0);


  analysisManager->CreateNtuple("sig2", "Energy");
  analysisManager->CreateNtupleDColumn(1,"first"); 
  analysisManager->CreateNtupleDColumn(1,"ene"); 
  analysisManager->FinishNtuple(1);



#if 0
  TFile *file = new TFile("hehe.root","recreate");
  file->Write();
  file->Close();
#endif

  //add new units for dose
  // 
#if 0
  const G4double milligray = 1.e-3*gray;
  const G4double microgray = 1.e-6*gray;
  const G4double nanogray  = 1.e-9*gray;  
  const G4double picogray  = 1.e-12*gray;
   
  new G4UnitDefinition("milligray", "milliGy" , "Dose", milligray);
  new G4UnitDefinition("microgray", "microGy" , "Dose", microgray);
  new G4UnitDefinition("nanogray" , "nanoGy"  , "Dose", nanogray);
  new G4UnitDefinition("picogray" , "picoGy"  , "Dose", picogray);       
#endif
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B3bRunAction::~B3bRunAction()
{
	delete G4AnalysisManager::Instance();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

 //G4Run* B3bRunAction::GenerateRun()
 //{ return new B3bRun; }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B3bRunAction::BeginOfRunAction(const G4Run* /*run*/)
{ 
	
  //  G4cout << "### Run " << run->GetRunID() << " start." << G4endl; 
  //inform the runManager to save random number seed
  // G4RunManager::GetRunManager()->SetRandomNumberStore(false);

	auto analysisManager = G4AnalysisManager::Instance(); 

	G4String fileName = "h";
	analysisManager->OpenFile(fileName);


	//	G4String fileName = "B3";
//	analysisManager->OpenFile(fileName);



}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B3bRunAction::EndOfRunAction(const G4Run* /*run*/)
{
#if 0
   G4int nofEvents = run->GetNumberOfEvent();
  if (nofEvents == 0) return;
#endif

  auto analysisManager = G4AnalysisManager::Instance();
 // analysisManager->GetH1(0);
 
  analysisManager->Write();
  analysisManager->CloseFile();





#if 0
  // Run conditions
  //  note: There is no primary generator action object for "master"
  //        run manager for multi-threaded mode.
  const B3PrimaryGeneratorAction* generatorAction
    = static_cast<const B3PrimaryGeneratorAction*>(
        G4RunManager::GetRunManager()->GetUserPrimaryGeneratorAction());
  G4String partName;
  if (generatorAction) 
  {
    G4ParticleDefinition* particle 
      = generatorAction->GetParticleGun()->GetParticleDefinition();
    partName = particle->GetParticleName();
  }  
  
  //results
  //
  const B3bRun* b3Run = static_cast<const B3bRun*>(run);
  G4int nbGoodEvents = b3Run->GetNbGoodEvents();
  G4double sumDose   = b3Run->GetSumDose();                           
#endif


#if 0       
  //print
  //
  if (IsMaster())
  {
    G4cout
     << G4endl
     << "--------------------End of Global Run-----------------------"
     << G4endl
     << "  The run was " << nofEvents << " events ";
  }
  else
  {
    G4cout
     << G4endl
     << "--------------------End of Local Run------------------------"
     << G4endl
     << "  The run was " << nofEvents << " "<< partName;
  }      
  G4cout
     << "; Nb of 'good' e+ annihilations: " << nbGoodEvents  << G4endl
     << " Total dose in patient : " << G4BestUnit(sumDose,"Dose") << G4endl  
     << "------------------------------------------------------------" << G4endl 
     << G4endl;
#endif

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
