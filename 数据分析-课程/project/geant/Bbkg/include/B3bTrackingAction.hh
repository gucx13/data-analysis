//#ifndef B3bEventAction_h     
//#define B3bEventAction_h 1          

#include "G4UserTrackingAction.hh"
#include "globals.hh"

class B3bEventAction;

class B3bTrackingAction : public G4UserTrackingAction {

	public:
		B3bTrackingAction(B3bEventAction* eventAction); 
		virtual ~B3bTrackingAction();
		virtual void BeginOfTrackingAction(const G4Track*);
		virtual void EndOfTrackingAction(const G4Track*);
	protected:
		G4TrackingManager* fpTrackingManager;

	private:
		B3bEventAction*  fEventAction;
};
