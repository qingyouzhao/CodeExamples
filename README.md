# CodeExamples
An Unreal Engine project to test engine concepts that are hard to find exact documentation



### GC behavior for interface reference UPROPERTY

### Swap base class of C++ component

If I have component `UMyMeshComponent` in C++

Derive a child class `UMyNextMeshComponent` in C++

Add `UMyNextMeshComponent` to a Blueprint class and save the blueprint class

Save that blueprint class 

Go back to C++, swap the base of `UMyNextMeshComponent` from `UMyMeshComponnt` to something else, say `UProceduralMeshComponent`, the blueprint will be broken on `Load`

This is something I am aiming to solve but not have any clue yet.