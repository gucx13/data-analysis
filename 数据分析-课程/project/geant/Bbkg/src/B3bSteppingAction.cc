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
// $Id: B4aSteppingAction.cc 68058 2013-03-13 14:47:43Z gcosmo $
// 
/// \file B4aSteppingAction.cc
/// \brief Implementation of the B4aSteppingAction class

#include "B3bSteppingAction.hh"
#include "B3bEventAction.hh"
#include "B3DetectorConstruction.hh"
#include "B3Analysis.hh"

#include "G4Step.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

#include "G4ParticleChange.hh"
#include "G4PhysicalConstants.hh"
#include "G4OpticalPhoton.hh"

//extern G4int nDetected;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B3bSteppingAction::B3bSteppingAction(
                      const B3DetectorConstruction* detectorConstruction,
                      B3bEventAction* eventAction)
  : G4UserSteppingAction(),
    fDetConstruction(detectorConstruction),
    fEventAction(eventAction)
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B3bSteppingAction::~B3bSteppingAction()
{ 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B3bSteppingAction::UserSteppingAction(const G4Step* step)
{
// Collect energy and track length step by step

  // get volume of the current step
  G4VPhysicalVolume* volume 
    = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
  G4Track* track = step->GetTrack();

  // energy deposit
  G4double edep = step->GetTotalEnergyDeposit();
  //G4ThreeVector p = step->GetPreStepPoint()->GetPosition();
  G4double e=step->GetPreStepPoint()->GetTotalEnergy();
  G4String name = step->GetTrack()->GetDefinition()->GetParticleName();
  if (volume == fDetConstruction->GetEff((int) 1)){
  	fEventAction->energy = fEventAction->energy + edep;
  }

 #if 0
  G4double lambda = h_Planck*c_light/e;

  const int num=46;
  G4double phLambda[num]=
  { 291.391,  291.45,  291.515,  291.579,  291.643, 
	295.976,  296.09,  306.783,  325.92,   349.232,
	370.395,  393.668, 419.031,  442.27,   459.158,
	482.387,  501.376, 518.26,   533.019,  547.773,
	558.303,  575.172, 587.807,  596.212,  606.736,
	613.021,  617.197, 623.492,  627.667,  633.952,
	638.122,  642.298, 648.588,  652.763,  659.043,
	663.214,  667.389, 671.559,  677.849,  684.14,
	686.2,    692.485, 696.656,  702.941,  705.001, 709.17 };

  G4double QE[num]=
  { 0.0100584,  0.013022,  0.0172256,  0.0227861,  0.0301416,
	0.047368,   0.0777034, 0.130281,   0.204833,   0.254196,
	0.271324,   0.283459,  0.265945,   0.238986,   0.210147,
	0.18089,    0.149127,  0.128339,   0.10579,    0.0853461,
	0.0703416,  0.0567518, 0.0448068,  0.0353714,  0.0285322,
	0.022043,   0.0173989, 0.0140329,  0.0110764,  0.00855725,
	0.00661059, 0.00521786,0.00411882, 0.00325106, 0.00245818,
	0.00189898, 0.0014989, 0.00115792, 0.000914024,0.000721503,
	0.000569458,0.000439943,0.000339862,0.000262565,0.000207234,
	0.000163573 };

  for(int i=0;i<num;i++)
	  phLambda[i]=phLambda[i]*nm;

 const std::vector<const G4Track*>* secondaries =
                            step->GetSecondaryInCurrentStep();

#endif












#if 0

  if (secondaries->size()>0) {
     for(unsigned int i=0; i<secondaries->size(); ++i) {
        if (secondaries->at(i)->GetParentID()>0) {
		 G4double energy = secondaries->at(i)->GetDynamicParticle()->GetTotalEnergy();
		 G4double l = h_Planck*c_light/energy;
           if(secondaries->at(i)->GetDynamicParticle()->GetParticleDefinition()
               == G4OpticalPhoton::OpticalPhotonDefinition() && ( l<=phLambda[num-1] && l>=phLambda[0] ) ){
              if (secondaries->at(i)->GetCreatorProcess()->GetProcessName()
               == "Scintillation") fEventAction->SciPro++;
              if (secondaries->at(i)->GetCreatorProcess()->GetProcessName()
               == "Cerenkov" ) fEventAction->CerenkovPro++;
           }
        }
     }
  }

  //if((track->GetCreatorProcess())->GetProcessName() == "Cerenkov")
	//fEventAction->CerenkovPro++;

for(int i=1;i<7;i++)
  if(volume == fDetConstruction->GetSci(i) /*&& (name == "e+" || name == "e-" || name == "mu+" || name == "mu-" )*/)
  {
	  fEventAction->AddEnergy(i,edep);
  }

	if(fEventAction->ifRecord())
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();


  if(track->GetTrackStatus()==fStopAndKill && track->GetDefinition()->GetParticleName()=="opticalphoton" && ( lambda<=phLambda[num-1] && lambda>=phLambda[0] ) )
  {
	  
	if(track->GetPosition().getY()==fDetConstruction->GetPMTPos('d'))
	{
		fEventAction->nAllDown++;
		if((track->GetCreatorProcess())->GetProcessName() == "Cerenkov")
		{
			analysisManager->FillNtupleDColumn(7, 0, lambda/nm);
			analysisManager->AddNtupleRow(7);  

		  fEventAction->nCerenkovDown++;
		}
		else 
		{
			analysisManager->FillNtupleDColumn(8, 0, lambda/nm);
			analysisManager->AddNtupleRow(8);  

			fEventAction->nScintillationDown++;

		}
		G4double ifqe = G4UniformRand();
		G4double eff=0;
		for(int j=0;j<num-2;j++)
		{
			if(lambda>phLambda[j] && lambda<=phLambda[j+1])
			{  
			  eff=QE[j]+(QE[j+1]-QE[j])/(phLambda[j+1]-phLambda[j])*(lambda-phLambda[j]);
			  break;
			}
		}
		
		
		if(ifqe<=eff)
		{
			fEventAction->nAllDownDet++;

		if((track->GetCreatorProcess())->GetProcessName() == "Cerenkov")
		{
			fEventAction->nCerenkovDownDet++;
			analysisManager->FillNtupleDColumn(3, 0, step->GetPreStepPoint()->GetGlobalTime());
			analysisManager->FillNtupleDColumn(3, 1, lambda/nm);
			analysisManager->AddNtupleRow(3);  

		}
		else 
		{
		  fEventAction->nScintillationDownDet++;
		  analysisManager->FillNtupleDColumn(5, 0, step->GetPreStepPoint()->GetGlobalTime());
			analysisManager->FillNtupleDColumn(5, 1, lambda/nm);
			analysisManager->AddNtupleRow(5);  
		}
		  fEventAction->downTime[fEventAction->nAllDownDet]=step->GetPreStepPoint()->GetGlobalTime();
		  //G4cout<<fEventAction->downTime[fEventAction->nAllDownDet]<<G4endl;
		//analysisManager->FillH1(1, step->GetPreStepPoint()->GetGlobalTime());
		analysisManager->FillNtupleDColumn(1, 0, step->GetPreStepPoint()->GetGlobalTime());
		analysisManager->FillNtupleDColumn(1, 1, lambda/nm);
		analysisManager->AddNtupleRow(1);  
		

		}

	}
	else if(track->GetPosition().getY()==fDetConstruction->GetPMTPos('u'))
	{
		fEventAction->nAllUp++;
		if((track->GetCreatorProcess())->GetProcessName() == "Cerenkov")
		{
			analysisManager->FillNtupleDColumn(9, 0, lambda/nm);
			analysisManager->AddNtupleRow(9);  
		
		  fEventAction->nCerenkovUp++;
		}
		  else
		  {
			analysisManager->FillNtupleDColumn(10, 0, lambda/nm);
			analysisManager->AddNtupleRow(10);  
			fEventAction->nScintillationUp++;

		  }
		G4double ifqe = G4UniformRand();
		G4double eff=0;
		for(int j=0;j<num-2;j++)
		{
			if(lambda>phLambda[j] && lambda<=phLambda[j+1])
			{  
			  eff=QE[j]+(QE[j+1]-QE[j])/(phLambda[j+1]-phLambda[j])*(lambda-phLambda[j]);
			  break;
			}
		}


		if(ifqe<=eff)
		{
			fEventAction->nAllUpDet++;

		if((track->GetCreatorProcess())->GetProcessName() == "Cerenkov")
		{
			fEventAction->nCerenkovUpDet++;
			analysisManager->FillNtupleDColumn(4, 0, step->GetPreStepPoint()->GetGlobalTime());
			analysisManager->FillNtupleDColumn(4, 1, lambda/nm);
			analysisManager->AddNtupleRow(4);  

		}

		else 
		{
		  fEventAction->nScintillationUpDet++;
		  analysisManager->FillNtupleDColumn(6, 0, step->GetPreStepPoint()->GetGlobalTime());
			analysisManager->FillNtupleDColumn(6, 1, lambda/nm);
			analysisManager->AddNtupleRow(6);  
		}
		fEventAction->upTime[fEventAction->nAllUpDet]=step->GetPreStepPoint()->GetGlobalTime();


    //analysisManager->FillH1(2, step->GetPreStepPoint()->GetGlobalTime());
	analysisManager->FillNtupleDColumn(2, 0, step->GetPreStepPoint()->GetGlobalTime());
			analysisManager->FillNtupleDColumn(2, 1, lambda/nm);
	analysisManager->AddNtupleRow(2);  
	//G4cout<<(track->GetCreatorProcess())->GetProcessName()<<G4endl;
	/*Scintillation Cerenkov*/
	/*G4cout<<"track: "<<(track->GetPosition().getZ())<<G4endl;
	G4cout<<"step pre: "<<(step->GetPreStepPoint()->GetPosition().getZ())<<G4endl;
	G4cout<<"step post: "<<step->GetPostStepPoint()->GetPosition().getZ()<<G4endl;*/
	}
	}

  }

}

#endif





}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
