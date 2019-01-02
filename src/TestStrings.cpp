/*
 * TestStrings.cpp
 *
 *  Created on: Dec 21, 2018
 *      Author: dan
 */

using namespace std;

#include <string>

extern const string  testString1 = "\
<Step Text=\"Load Radio 1 codeplug\">\n\
<Action Id=\"LOADCODEPLUG\" ControllerId=\"Radio1\">\n\
<Property Id=\"LOADCODEPLUG\" Value=\"AMP_IPS_TC1_TC2_SU1.pba\">\n\
<Property Id=\"LOADTYPE\" Value=\"{PBA}\" />\n\
</Property>\n\
</Action>\n\
</Step>\n";

extern const string testString3 = "\
<TestCase>\n\
<DataProject>Astro</DataProject>\n\
<DataParentId>41234</DataParentId>\n\
</TestCase>\n";

extern const string testString6[] = "\
      <Step Text=\"Load Radio 1 codeplug\">\n\
        <Action Id=\"LOADCODEPLUG\" ControllerId=\"Radio1\">\n\
          <Property Id=\"LOADCODEPLUG\" Value=\"AMP_IPS_TC1_TC2_SU1.pba\">\n\
            <Property Id=\"LOADTYPE\" Value=\"{PBA}\" />\n\
          </Property>\n\
        </Action>\n\
      </Step>\n";
