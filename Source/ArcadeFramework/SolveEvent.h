#pragma once

class APuzzleSolver;

class SolveEvent
{
public:
    SolveEvent() {}
    virtual ~SolveEvent() {}
    
    virtual void onPuzzleSolved(int index, APuzzleSolver* puzzle) = 0;
    
    virtual void onAllPuzzleSolved() = 0;    
};
