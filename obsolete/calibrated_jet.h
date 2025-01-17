#ifndef CALIBRATED_JET_H
#define CALIBRATED_JET_H


#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 
#include <sstream>
#include <ostream>
#include <stdexcept>
#include <cmath>

#include "fastjet/ClusterSequence.hh"


namespace MOD {
   class CalibratedJet {

      public:
         CalibratedJet(double px, double py, double pz, double energy, std::string algorithm, double JEC, double area, int number_of_constituents, int charged_multiplicity, double neutral_hadron_fraction, double neutral_em_fraction, double charged_hadron_fraction, double charged_em_fraction);
         CalibratedJet(fastjet::PseudoJet pseudojet, std::string algorithm, double JEC, double area, int number_of_constituents, int charged_multiplicity, double neutral_hadron_fraction, double neutral_em_fraction, double charged_hadron_fraction, double charged_em_fraction);
         CalibratedJet(std::istringstream & input_stream);
         CalibratedJet();

         bool is_valid() const;
         
         std::string algorithm() const;
         std::string make_string() const;

         std::string make_header_string() const;

         double JEC() const;

         double area() const;

         double neutral_hadron_fraction() const;
         double neutral_em_fraction() const;
         int number_of_constituents() const;

         double charged_hadron_fraction() const;
         int charged_multiplicity() const;
         double charged_em_fraction() const;

         MOD::CalibratedJet corrected_jet();

         fastjet::PseudoJet uncorrected_pseudojet() const;
         fastjet::PseudoJet corrected_pseudojet() const;


         const int jet_quality();

         friend std::ostream& operator<< (std::ostream&, const CalibratedJet&);

         bool operator<(const CalibratedJet& rhs) const;

         bool operator==(const CalibratedJet& rhs) const;

      private:
         fastjet::PseudoJet _pseudojet;
         double _mass;
         std::string _algorithm;
         double _JEC;

         double _area;

         int _number_of_constituents;
         int _charged_multiplicity;
         double _neutral_hadron_fraction;
         double _neutral_em_fraction;
         double _charged_hadron_fraction;
         double _charged_em_fraction;

         enum JetQualityLevels_t { UNDETERMINED = -1, FAILED = 0, LOOSE = 1, MEDIUM = 2, TIGHT = 3 };
         JetQualityLevels_t _jet_quality;
   };
}



#endif /* CALIBRATED_JET_H */