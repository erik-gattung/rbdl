^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package rbdl
^^^^^^^^^^^^^^^^^^^^^^^^^^

0.4.0 (2022-04-08)
------------------
* Merge branch 'dynamic_linearized_mpc' into 'erbium-devel'
  Add global inertia matrix from COM method
  See merge request control/rbdl!17
* Merge branch 'update_ik_api_from_upstream' into 'erbium-devel'
  Update new InverseKinematics with different constraints API
  See merge request control/rbdl!18
* Update new InverseKinematics with different constraints API
* Add global inertia matrix from COM method
* Contributors: Adria Roig, Sai Kishor Kothakota, saikishor

0.3.0 (2021-08-29)
------------------
* Merge branch 'kangaroo_wbc' into 'erbium-devel'
  Compute ZMP kinetimatically and partiall mass methods
  See merge request control/rbdl!16
* Compute ZMP kinetimatically and partiall mass methods
* Contributors: Adria Roig, victor

0.2.12 (2019-11-06)
-------------------
* Merge branch 'gcc-warning' into 'erbium-devel'
  Gcc warning
  See merge request control/rbdl!15
* disable false positives errors on tests
* Disable shadowed variable
* Disable gcc uninitialized
* Contributors: Victor Lopez

0.2.11 (2019-09-05)
-------------------
* Merge branch 'melodic-devel' into 'erbium-devel'
  Melodic devel
  See merge request control/rbdl!14
* Fix build errors
* Use urdf compatibility typedefs for kinetic/melodic compatibility
* Fix float comparison
* Add missing SYSTEM to include_directories
* migrated to melodic
* Contributors: Hilario Tome, Victor Lopez

0.2.10 (2019-07-24)
-------------------
* Merge branch 'inertia_id' into 'erbium-devel'
  Inertia
  See merge request control/rbdl!13
* cleanup of the relative stuff
* adding relative quantities
* added relative computations
* Contributors: Hilario Tome

0.2.9 (2019-03-29)
------------------
* Merge branch 'clang-fixes' into 'erbium-devel'
  Wrong usage of template keyword
  See merge request control/rbdl!12
* Wrong usage of template keyword
* Contributors: Victor Lopez

0.2.8 (2019-03-18)
------------------
* Merge branch 'com_template' into 'erbium-devel'
  Com template
  See merge request control/rbdl!11
* fixed critical bug in forward dynamics with multidof joint
* templetized some functions
* Merge branch 'faster-getbodyid' into 'erbium-devel'
  Twice as fast getbodyid
  See merge request control/rbdl!8
* Twice as fast getbodyid
* Contributors: Hilario Tome, Victor Lopez

0.2.7 (2018-11-15)
------------------
* Merge branch 'clang-fixes' into 'erbium-devel'
  Fix wrong usage of dependent template
  See merge request control/rbdl!9
* Fix wrong usage of dependent template
* Contributors: Victor Lopez

0.2.6 (2018-07-06)
------------------
* Merge branch 'as_test_fix' into 'erbium-devel'
  Fix uninitialized values in urdfreader.
  See merge request control/rbdl!7
* Fix uninitialized values in urdfreader.
* Contributors: Hilario Tome, alexandersherikov

0.2.5 (2018-06-08)
------------------
* Merge branch 'continuous_joint' into 'erbium-devel'
  changed how continous joint limit is parsed
  See merge request control/rbdl!5
* Fix: velocity bounds for continuous joints
* changed how continous joint limit is parsed
* Contributors: Hilario Tome, alexandersherikov

0.2.4 (2018-04-17)
------------------
* Merge branch 'pose_offset_test' into 'erbium-devel'
  Add pose offset API
  See merge request control/rbdl!3
* Clang format
* Fix rebase issues
* Fix compilling issues
* Add pose offset API
* Contributors: Adria Roig, Hilario Tome

0.2.3 (2018-04-06)
------------------
* Merge branch 'link_reference_to' into 'erbium-devel'
  added get transform with respect to other link
  See merge request control/rbdl!4
* added get transform with respect to other link
* Contributors: Hilario Tome

0.2.2 (2018-02-14)
------------------
* Merge branch 'as-urdfreader-linkskip' into 'erbium-devel'
  urdfreader: added functions to read URDF without given links
  See merge request control/rbdl!1
* Merge branch 'erbium-devel' into as-urdfreader-linkskip
* Dummy commit to trigger recursive testing
* Use quaternions instead of RPY angles to set joint transformations.
  Previous version seem to be introducing noise due to conversions back
  and forth (quaternion -> RPY -> rotation matrix).
* Model: added const getModelData().
* URDF reader: allow explicit specification of the kinamatic root link.
* URDF reader: minor changes in the logic
* Minor bugfix in URDF reader.
* Omit links in URDFModel: deleted corresponding functions from URDF reader
* urdfreader: code deduplication & cleanup
* Merge branch 'erbium-devel' into as-urdfreader-linkskip
  Conflicts:
  addons/urdfreader/urdfreader.cc
* urdfreader: drop unnecessary piece of code.
* Merge branch 'erbium-devel' into as-urdfreader-linkskip
  Conflicts:
  addons/urdfreader/urdfreader.cc
* Merge 'erbium-devel', cleanups, deduplications.
  Conflicts:
  addons/urdfreader/urdfreader.cc
  include/rbdl/addons/urdfreader/urdfreader.h
* Merge branch 'erbium-devel' into as-urdfreader-linkskip
  Conflicts:
  addons/urdfreader/urdfreader.cc
* urdfreader: added functions to read URDF without given links
  + some refactoring and partial formatting.
* Contributors: Hilario Tome, alexandersherikov

0.2.1 (2018-02-13)
------------------
* fixed compilation isnan
* Contributors: Hilario Tome

0.2.0 (2018-01-19)
------------------
* more templetization
* added rbdl parser function
* Merge branch 'erbium-devel' of gitlab:control/rbdl into erbium-devel
* fix template quaternion
* added extra parser
* changed rbdl root name for fixed floating base
* more bug fixes
* added proper root naming in fixed base rbdl
* fixed merge
* fixed critical bug in set body quaternion, the code was commented
* formating
* more templetization
* more templetization
* added specializations
* formating
* fixed utils
* more migration
* more migration
* fixed getter enum compile warking treated as error
* added better enum
* Merge branch 'dubnium-devel' into erbium-devel
* added get point angular acceleration and helper functions
* progres
* Merge branch 'dubnium-devel' into erbium-devel
* added helper util
* Added NO_TYPE floatingBaseType for grasping simulator
* unified utils
* More templetization
* Separated model data into a different header file
* Continue refactoring
* Broken commit, progress in having model as const
* Fixed bug
* Added model_data structure
* Templatized basic math operations
* Added coment
* Added utils
* Contributors: Adrià Roig, Hilario Tome, Hilario Tomé

0.1.1 (2016-10-14)
------------------
* Added conversion of mimic joints to fixed joints
* Contributors: Hilario Tome

0.1.0 (2016-10-05)
------------------
* Fixed cppecheck errors
* Update README.md
* Added gtests
* Updated to new RBDL version
* Update rbdl parser to parse urdf model
* Merge branch 'dubnium-devel' of gitlab:control/rbdl into dubnium-devel
* Added momentum computation
* Contributors: Hilario Tome

0.0.2 (2016-03-07)
------------------
* Added 2d floating base support
* Changed catkin package order in CMakeLists
* Aded various fixes and removed logging
* Removed unnecesary joint variable that created an allocation in update custom allocation
* Fixed allocation in joint
* Contributors: Hilario Tome

0.0.1 (2015-01-13)
------------------
* Release
