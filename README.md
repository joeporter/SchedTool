SchedTool: New and improved command-line scheduling tool.

Uses simple text language for defining scheduling problems. See the 
test directory for examples.

Does require ANTLR 3 (generator), the ANTLR 3 C runtime library, and 
Gecode 3.2.2 (old version).  None of these are included.

Work in progress:
Unsatisfiable core extraction
Partial models

Making sense of the code:

* ConfigKeeper -- command-line handler and global storage for configuration.
                (Singleton pattern)
* SchedTool -- main program wrapper.  Calls command line setup, input parsing,
             and then the schedule generation infrastructure
* schedAdapter -- allows C functions (ANTLR-generated) to call C++ classes to 
                build scheduling models
* schedModel -- Lightweight classes for processors, buses, tasks, messages --
              all of the high-level objects from the input file.  It also
              captures the relationships between them so they can be looked
              up during schedule generation steps. (Template pattern)
* defaultSchedModel -- "Standard" scheduling model.
* debugSchedModel -- highly experimental scheduling model that tries to extract
              unsatisfiable cores for infeasible models (incomplete).
* CPEngine -- Implementation of the actual search.  This invokes the Gecode API
            to build the constraints, and specifies the branching model.
* InstanceKeeper -- Maintains the association between task/msg names and indices
            representing task/msg instances in the constraint model.
* solverAdapter -- abstract API for the solver (future expansion).


