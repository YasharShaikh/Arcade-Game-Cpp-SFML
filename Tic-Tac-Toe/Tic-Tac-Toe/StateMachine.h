#pragma once
#include <memory>
#include <stack>


#include "State.h"

namespace arcade
{
	typedef std::unique_ptr<State> stateRef;


	class StateMachine
	{

	public:
		StateMachine() {};
		~StateMachine() {};


		void AddState(stateRef newState, bool isReplacing = true) ;
		void RemoveState();

		void ProcessStateChanges();


		stateRef& getActiveState();


	private:
		std::stack<stateRef> _states;
		stateRef _newState;

		bool _isRemoving;
		bool _isAdding;
		bool _isReplacing;


	};
}