/*
 *    Copyright (c) 2013 Battelle Memorial Institute
 *    Licensed under modified BSD License. A copy of this license can be found
 *    in the LICENSE file in the top level directory of this distribution.
 */
/*
 *  Created on: June 17, 2016
 *      Author: Bruce Palmer
 */
#ifndef EXDC1_HPP
#define EXDC1_HPP
#include "gridpack/component/data_collection.hpp"
#include "gridpack/parser/dictionary.hpp"
#include "gridpack/utilities/string_utils.hpp"
namespace gridpack {
namespace parser {
template <class _data_struct> class Exdc1Parser
{
  public:
    /**
     * Constructor
     */
    explicit Exdc1Parser()
    {
    }

    /**
     * Destructor
     */
    virtual ~Exdc1Parser()
    {
    }

    /**
     * Extract data from _data_struct and store it in data collection object
     * @param data_struct data struct object
     * @param data data collection object
     * @param model name of generator model
     * @param gen_id index of generator
     */
    void extract(_data_struct &data_struct,
        gridpack::component::DataCollection *data, std::string &model,
        int g_id)
    {
      double rval;
      bool bval;
      // HAS_EXCITER
      if (!data->getValue(HAS_EXCITER,&bval,g_id)) {
        data->addValue(HAS_EXCITER, true, g_id);
      } else {
        data->setValue(HAS_EXCITER, true, g_id);
      }

      // EXCITER_MODEL
      if (!data->getValue(EXCITER_MODEL,&model,g_id)) {
        data->addValue(EXCITER_MODEL, data_struct.gen_model, g_id);
      } else {
        data->setValue(EXCITER_MODEL, data_struct.gen_model, g_id);
      }

      // EXCITER_TR
      if (!data->getValue(EXCITER_TR,&rval,g_id)) {
        data->addValue(EXCITER_TR, data_struct.tr, g_id);
      } else {
        data->setValue(EXCITER_TR, data_struct.tr, g_id);
      }

      // EXCITER_KA
      if (!data->getValue(EXCITER_KA,&rval,g_id)) {
        data->addValue(EXCITER_KA, data_struct.ka, g_id);
      } else {
        data->setValue(EXCITER_KA, data_struct.ka, g_id);
      }

      // EXCITER_TA
      if (!data->getValue(EXCITER_TA,&rval,g_id)) {
        data->addValue(EXCITER_TA, data_struct.ta, g_id);
      } else {
        data->setValue(EXCITER_TA, data_struct.ta, g_id);
      }

      // EXCITER_TB
      if (!data->getValue(EXCITER_TB,&rval,g_id)) {
        data->addValue(EXCITER_TB, data_struct.tb, g_id);
      } else {
        data->setValue(EXCITER_TB, data_struct.tb, g_id);
      }

      // EXCITER_TC
      if (!data->getValue(EXCITER_TC,&rval,g_id)) {
        data->addValue(EXCITER_TC, data_struct.tc, g_id);
      } else {
        data->setValue(EXCITER_TC, data_struct.tc, g_id);
      }

      // EXCITER_VRMAX
      if (!data->getValue(EXCITER_VRMAX,&rval,g_id)) {
        data->addValue(EXCITER_VRMAX, data_struct.vrmax, g_id);
      } else {
        data->setValue(EXCITER_VRMAX, data_struct.vrmax, g_id);
      }

      // EXCITER_VRMIN
      if (!data->getValue(EXCITER_VRMIN,&rval,g_id)) {
        data->addValue(EXCITER_VRMIN, data_struct.vrmin, g_id);
      } else {
        data->setValue(EXCITER_VRMIN, data_struct.vrmin, g_id);
      }

      // EXCITER_KE
      if (!data->getValue(EXCITER_KE,&rval,g_id)) {
        data->addValue(EXCITER_KE, data_struct.ke, g_id);
      } else {
        data->setValue(EXCITER_KE, data_struct.ke, g_id);
      }

      // EXCITER_TE
      if (!data->getValue(EXCITER_TE,&rval,g_id)) {
        data->addValue(EXCITER_TE, data_struct.te, g_id);
      } else {
        data->setValue(EXCITER_TE, data_struct.te, g_id);
      }

      // EXCITER_KF
      if (!data->getValue(EXCITER_KF,&rval,g_id)) {
        data->addValue(EXCITER_KF, data_struct.kf, g_id);
      } else {
        data->setValue(EXCITER_KF, data_struct.kf, g_id);
      }

      // EXCITER_TF1
      if (!data->getValue(EXCITER_TF1,&rval,g_id)) {
        data->addValue(EXCITER_TF1, data_struct.tf1, g_id);
      } else {
        data->setValue(EXCITER_TF1, data_struct.tf1, g_id);
      }

      // EXCITER_SWITCH
      if (!data->getValue(EXCITER_SWITCH,&rval,g_id)) {
        data->addValue(EXCITER_SWITCH, data_struct.rswitch, g_id);
      } else {
        data->setValue(EXCITER_SWITCH, data_struct.rswitch, g_id);
      }

      // EXCITER_E1
      if (!data->getValue(EXCITER_E1,&rval,g_id)) {
        data->addValue(EXCITER_E1, data_struct.e1, g_id);
      } else {
        data->setValue(EXCITER_E1, data_struct.e1, g_id);
      }

      // EXCITER_SE1
      if (!data->getValue(EXCITER_SE1,&rval,g_id)) {
        data->addValue(EXCITER_SE1, data_struct.se1, g_id);
      } else {
        data->setValue(EXCITER_SE1, data_struct.se1, g_id);
      }

      // EXCITER_E2
      if (!data->getValue(EXCITER_E2,&rval,g_id)) {
        data->addValue(EXCITER_E2, data_struct.e2, g_id);
      } else {
        data->setValue(EXCITER_E2, data_struct.e2, g_id);
      }

      // EXCITER_SE2
      if (!data->getValue(EXCITER_SE2,&rval,g_id)) {
        data->addValue(EXCITER_SE2, data_struct.se2, g_id);
      } else {
        data->setValue(EXCITER_SE2, data_struct.se2, g_id);
      }
    }

    /**
     * Parser list of strings and store results in data collection object
     * @param split_line list of tokens from .dyr file
     * @param data data collection object
     * @param model name of generator model
     * @param gen_id index of generator
     */
    void parse(std::vector<std::string> &split_line,
        gridpack::component::DataCollection *data, std::string &model,
        int g_id)
    {
      double rval;
      bool bval;
      int nstr = split_line.size();
      // HAS_EXCITER
      if (!data->getValue(HAS_EXCITER,&bval,g_id)) {
        data->addValue(HAS_EXCITER, true, g_id);
      } else {
        data->setValue(HAS_EXCITER, true, g_id);
      }

      // EXCITER_MODEL
      std::string stmp;
      if (!data->getValue(EXCITER_MODEL,&stmp,g_id)) {
        data->addValue(EXCITER_MODEL, model.c_str(), g_id);
      } else {
        data->setValue(EXCITER_MODEL, model.c_str(), g_id);
      }

      // EXCITER_TR
      if (nstr > 3) {
        if (!data->getValue(EXCITER_TR,&rval,g_id)) {
          data->addValue(EXCITER_TR,
              atof(split_line[3].c_str()), g_id);
        } else {
          data->setValue(EXCITER_TR,
              atof(split_line[3].c_str()), g_id);
        }
      } 

      // EXCITER_KA
      if (nstr > 4) {
        if (!data->getValue(EXCITER_KA,&rval,g_id)) {
          data->addValue(EXCITER_KA,
              atof(split_line[4].c_str()), g_id);
        } else {
          data->setValue(EXCITER_KA,
              atof(split_line[4].c_str()), g_id);
        }
      } 

      // EXCITER_TA
      if (nstr > 5) {
        if (!data->getValue(EXCITER_TA,&rval,g_id)) {
          data->addValue(EXCITER_TA,
              atof(split_line[5].c_str()), g_id);
        } else {
          data->setValue(EXCITER_TA,
              atof(split_line[5].c_str()), g_id);
        }
      }

      // EXCITER_TB
      if (nstr > 6) {
        if (!data->getValue(EXCITER_TB,&rval,g_id)) {
          data->addValue(EXCITER_TB,
              atof(split_line[6].c_str()), g_id);
        } else {
          data->setValue(EXCITER_TB,
              atof(split_line[6].c_str()), g_id);
        }
      }

      // EXCITER_TC
      if (nstr > 7) {
        if (!data->getValue(EXCITER_TC,&rval,g_id)) {
          data->addValue(EXCITER_TC,
              atof(split_line[7].c_str()), g_id);
        } else {
          data->setValue(EXCITER_TC,
              atof(split_line[7].c_str()), g_id);
        }
      }

      // EXCITER_VRMAX
      if (nstr > 8) {
        if (!data->getValue(EXCITER_VRMAX,&rval,g_id)) {
          data->addValue(EXCITER_VRMAX,
              atof(split_line[8].c_str()), g_id);
        } else {
          data->setValue(EXCITER_VRMAX,
              atof(split_line[8].c_str()), g_id);
        }
      } 

      // EXCITER_VRMIN
      if (nstr > 9) {
        if (!data->getValue(EXCITER_VRMIN,&rval,g_id)) {
          data->addValue(EXCITER_VRMIN,
              atof(split_line[9].c_str()), g_id);
        } else {
          data->setValue(EXCITER_VRMIN,
              atof(split_line[9].c_str()), g_id);
        }
      } 

      // EXCITER_KE
      if (nstr > 10) {
        if (!data->getValue(EXCITER_KE,&rval,g_id)) {
          data->addValue(EXCITER_KE,
              atof(split_line[10].c_str()), g_id);
        } else {
          data->setValue(EXCITER_KE,
              atof(split_line[10].c_str()), g_id);
        }
      } 

      // EXCITER_TE
      if (nstr > 11) {
        if (!data->getValue(EXCITER_TE,&rval,g_id)) {
          data->addValue(EXCITER_TE,
              atof(split_line[11].c_str()), g_id);
        } else {
          data->setValue(EXCITER_TE,
              atof(split_line[11].c_str()), g_id);
        }
      } 

      // EXCITER_KF
      if (nstr > 12) {
        if (!data->getValue(EXCITER_KF,&rval,g_id)) {
          data->addValue(EXCITER_KF,
              atof(split_line[12].c_str()), g_id);
        } else {
          data->setValue(EXCITER_KF,
              atof(split_line[12].c_str()), g_id);
        }
      } 

      // EXCITER_TF1
      if (nstr > 13) {
        if (!data->getValue(EXCITER_TF1,&rval,g_id)) {
          data->addValue(EXCITER_TF1,
              atof(split_line[13].c_str()), g_id);
        } else {
          data->setValue(EXCITER_TF1,
              atof(split_line[13].c_str()), g_id);
        }
      } 

      // EXCITER_SWITCH
      if (nstr > 14) {
        if (!data->getValue(EXCITER_SWITCH,&rval,g_id)) {
          data->addValue(EXCITER_SWITCH,
              atof(split_line[14].c_str()), g_id);
        } else {
          data->setValue(EXCITER_SWITCH,
              atof(split_line[14].c_str()), g_id);
        }
      } 

      // EXCITER_E1
      if (nstr > 15) {
        if (!data->getValue(EXCITER_E1,&rval,g_id)) {
          data->addValue(EXCITER_E1,
              atof(split_line[15].c_str()), g_id);
        } else {
          data->setValue(EXCITER_E1,
              atof(split_line[15].c_str()), g_id);
        }
      } 

      // EXCITER_SE1
      if (nstr > 16) {
        if (!data->getValue(EXCITER_SE1,&rval,g_id)) {
          data->addValue(EXCITER_SE1,
              atof(split_line[16].c_str()), g_id);
        } else {
          data->setValue(EXCITER_SE1,
              atof(split_line[16].c_str()), g_id);
        }
      } 

      // EXCITER_E2
      if (nstr > 17) {
        if (!data->getValue(EXCITER_E2,&rval,g_id)) {
          data->addValue(EXCITER_E2,
              atof(split_line[17].c_str()), g_id);
        } else {
          data->setValue(EXCITER_E2,
              atof(split_line[17].c_str()), g_id);
        }
      } 

      // EXCITER_SE2
      if (nstr > 18) {
        if (!data->getValue(EXCITER_SE2,&rval,g_id)) {
          data->addValue(EXCITER_SE2,
              atof(split_line[18].c_str()), g_id);
        } else {
          data->setValue(EXCITER_SE2,
              atof(split_line[18].c_str()), g_id);
        }
      } 
    }

    /**
     * Parse list of strings store results in data_struct object
     * @param split_line list of tokens from .dyr file
     * @param data data struct that stores information from file
     */
    void store(std::vector<std::string> &split_line,_data_struct &data)
    {
      int nstr = split_line.size();
      // EXCITER_TR
      if (nstr > 3) {
        data.tr = atof(split_line[3].c_str());
      }

      // EXCITER_KA
      if (nstr > 4) {
        data.ka = atof(split_line[4].c_str());
      }

      // EXCITER_TA
      if (nstr > 5) {
        data.ta = atof(split_line[5].c_str());
      }

      // EXCITER_TB
      if (nstr > 6) {
        data.tb = atof(split_line[6].c_str());
      }

      // EXCITER_TC
      if (nstr > 7) {
        data.tc = atof(split_line[7].c_str());
      }

      // EXCITER_VRMAX
      if (nstr > 8) {
        data.vrmax = atof(split_line[8].c_str());
      }

      // EXCITER_VRMIN
      if (nstr > 9) {
        data.vrmin = atof(split_line[9].c_str());
      }

      // EXCITER_KE
      if (nstr > 10) {
        data.ke = atof(split_line[10].c_str());
      }

      // EXCITER_TE
      if (nstr > 11) {
        data.te = atof(split_line[11].c_str());
      }

      // EXCITER_KF
      if (nstr > 12) {
        data.kf = atof(split_line[12].c_str());
      }

      // EXCITER_TF1
      if (nstr > 13) {
        data.tf1 = atof(split_line[13].c_str());
      }

      // EXCITER_SWITCH
      if (nstr > 14) {
        data.rswitch = atof(split_line[14].c_str());
      }

      // EXCITER_E1
      if (nstr > 15) {
        data.e1 = atof(split_line[15].c_str());
      }

      // EXCITER_SE1
      if (nstr > 16) {
        data.se1 = atof(split_line[16].c_str());
      }

      // EXCITER_E2
      if (nstr > 17) {
        data.e2 = atof(split_line[17].c_str());
      }

      // EXCITER_SE2
      if (nstr > 18) {
        data.se2 = atof(split_line[18].c_str());
      }
    }
};
}  // parser
}  // gridpack
#endif
