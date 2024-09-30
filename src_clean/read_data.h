//#include "VDW_Coulomb.cuh"

void Check_Inputs_In_read_data_cpp(std::string& exepath);

void read_number_of_sims_from_input(size_t *NumSims, bool *SingleSim);

void read_FFParams_from_input(ForceField& FF, double& precision);

void read_Gibbs_and_Cycle_Stats(Gibbs& GibbsStatistics, bool& SetMaxStep, size_t& MaxStepPerCycle);

void read_simulation_input(bool *UseGPUReduction, bool *Useflag, bool *noCharges, int *InitializationCycles, int *EquilibrationCycles, int *ProductionCycles, size_t *NumberOfTrialPositions, size_t *NumberOfTrialOrientations, double *Pressure, double *Temperature, size_t *AllocateSize, bool *ReadRestart, int *RANDOMSEED, bool *SameFrameworkEverySimulation, int3& NumberOfComponents);

void ReadFramework(Boxsize& Box, PseudoAtomDefinitions& PseudoAtom, size_t FrameworkIndex, Components& SystemComponents);

void ReadFrameworkComponentMoves(Move_Statistics& MoveStats, Components& SystemComponents, size_t comp);

//void POSCARParser(Boxsize& Box, Atoms& Framework, PseudoAtomDefinitions& PseudoAtom);

void ForceFieldParser(ForceField& FF, PseudoAtomDefinitions& PseudoAtom);

void PseudoAtomParser(ForceField& FF, PseudoAtomDefinitions& PseudoAtom);

void MoleculeDefinitionParser(Atoms& Mol, Components& SystemComponents, std::string MolName, PseudoAtomDefinitions PseudoAtom, size_t Allocate_space);

void read_component_values_from_simulation_input(Components& SystemComponents, Move_Statistics& MoveStats, size_t AdsorbateComponent, Atoms& Mol, PseudoAtomDefinitions PseudoAtom, size_t Allocate_space);

void ReadRestartInputFileType(Components& SystemComponents);

void LMPDataFileParser(Boxsize& Box, Components& SystemComponents);

void RestartFileParser(Boxsize& Box, Components& SystemComponents);

void read_Ewald_Parameters_from_input(double CutOffCoul, Boxsize& Box, double precision);

void OverWrite_Mixing_Rule(ForceField& FF, PseudoAtomDefinitions& PseudoAtom);

void OverWriteTailCorrection(Components& SystemComponents, ForceField& FF, PseudoAtomDefinitions& PseudoAtom);

void read_movies_stats_print(Components& SystemComponents);

std::vector<double2> ReadMinMax();
void ReadDNNModelSetup(Components& SystemComponents);
//###PATCH_LCLIN_READDATA_H###//
//###PATCH_ALLEGRO_READDATA_H###//

//Weird issues with using vector.data() for double and double3//
//So we keep this function, for now//
template<typename T>
T* convert1DVectortoArray(std::vector<T>& Vector)
{
  size_t Vectorsize = Vector.size();
  T* result=new T[Vectorsize];
  T* walkarr=result;
  std::copy(Vector.begin(), Vector.end(), walkarr);
  //printf("done convert Mol Type, Origin: %zu, copied: %zu\n", MoleculeTypeArray[0], result[0]);
  return result;
}

//void write_ReplicaPos(auto& pos, auto& ij2type, size_t ntotal, size_t nstep);

//void write_edges(auto& edges, auto& ij2type, size_t nedges, size_t nstep);
