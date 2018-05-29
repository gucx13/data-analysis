//#ifndef B3bEventAction_h     
//#define B3bEventAction_h 1          

#include "G4UserEventAction.hh"
#include "globals.hh"


class B3bRunAction;

class B3bEventAction : public G4UserEventAction {

	public:
		B3bEventAction(); 
		virtual ~B3bEventAction();

		virtual void BeginOfEventAction(const G4Event* event);
		virtual void EndOfEventAction(const G4Event* event);

		G4int eventID;                       
		G4double energy; 



	protected:
		G4EventManager* fpEventManager;
};
