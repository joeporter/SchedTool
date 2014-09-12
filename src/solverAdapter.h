
#ifndef _SOLVER_ADAPTER_H_
#define _SOLVER_ADAPTER_H_

#include <string>
#include <vector>
#include <map>

// Class interface for discrete solver
class SolverAdapter
{
public:
	SolverAdapter(void);
	virtual ~SolverAdapter(void);

	// Factory method for solver
	static SolverAdapter * GetSolver( std::string & solvername );

	// High-level convenience functions for building constraints
	virtual void SerializeInstances( std::vector< std::string > & instnames, std::vector< unsigned long long > & instsizes ) = 0;
	virtual void OrderInstances( std::vector< std::string > & instnames, unsigned long long dist, unsigned long long dur, bool strict = true ) = 0;
	virtual void EnforceDuration( std::vector< std::string > & instnames, unsigned long long dur ) = 0;
	virtual void AddLatencyBound( std::vector< std::string > & sndrnames, std::vector< std::string > & rcvrnames, unsigned long long maxdist ) = 0;
	virtual void AddLocalDependency( const std::string & sndrname, const std::string & rcvrname, unsigned long long sndrdur ) = 0;
    virtual void AddSyncMsg( const std::string & msgname, unsigned long long msgdur, unsigned long long minpos, unsigned long long maxpos ) = 0;
	virtual void AddTaskOffset( const std::string & taskname, unsigned long long taskdur, unsigned long long minpos, unsigned long long maxpos ) = 0;
	virtual void AddMsgOffset( const std::string & msgname, unsigned long long msgdur, unsigned long long minpos, unsigned long long maxpos ) = 0;

	// Low-level interface for building constraints
	virtual void AddVariable( const std::string & instname ) = 0;

	// Invocation
	virtual bool Solve() = 0;

	// Collecting results
	virtual void CollectInstances( std::map< std::string, unsigned long long > & inst_results ) = 0;
	virtual void CollectDebugInfo( std::vector< std::string > & dbg_results, bool & feas, bool & empty ) = 0;
};


#endif // _SOLVER_ADAPTER_H_
