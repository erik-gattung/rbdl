#ifndef _RBDL_UTILS_
#define _RBDL_UTILS_

#include <Eigen/Dense>
#include <exception>
#include <rbdl/Kinematics.h>

inline Eigen::Isometry3d getBodyToBaseTransform(RigidBodyDynamics::Model &model, const Eigen::VectorXd &Q, const std::string &name, bool update){

  assert(model.dof_count == Q.rows());
  unsigned int id = model.GetBodyId(name.c_str());

  Eigen::Vector3d position = RigidBodyDynamics::CalcBodyToBaseCoordinates(model, Q, id, Eigen::Vector3d(0., 0., 0.), update);
  Eigen::Matrix3d rotation = RigidBodyDynamics::CalcBodyWorldOrientation(model, Q, id, update).transpose();

  Eigen::Isometry3d temp;
  temp.setIdentity();
  temp = ( Eigen::AngleAxisd(rotation) );
  temp.translation() = position;
  return temp;

}

inline Eigen::Isometry3d getBodyTransform(RigidBodyDynamics::Model &model, const std::string &name){
  unsigned int id = model.GetBodyId(name.c_str());
  RigidBodyDynamics::Math::SpatialTransform tf;
  //Add forces (check if contact force is not in a fix link)
  if(id >= model.fixed_body_discriminator){
    tf = model.mFixedBodies[id - model.fixed_body_discriminator].mParentTransform;
  }
  else{
    tf = model.X_lambda[id];
  }

  Eigen::Matrix3d Et = tf.E.transpose();

  Eigen::Isometry3d temp;
  temp.setIdentity();
  temp = ( Eigen::AngleAxisd(Et) );
  temp.translation() = tf.r;
  return temp;

}

inline unsigned int getParentBodyId(RigidBodyDynamics::Model &model, const std::string &name){
  unsigned int id = model.GetBodyId(name.c_str());
  //Add forces (check if contact force is not in a fix link)
  if(id >= model.fixed_body_discriminator){
    return model.mFixedBodies[id - model.fixed_body_discriminator].mMovableParent;
  }
  else{
    return model.lambda[id];
  }
}


inline void createGeneralizedVector(const Eigen::Vector3d &floatingBasePosition, const Eigen::Quaterniond &floatingBaseOrientation,
                                    const Eigen::VectorXd &jointStates, Eigen::VectorXd &state){

  if(state.rows() != jointStates.rows() + 7){
    throw std::runtime_error("Missmatch between vectors creating generalized vector");
  }

  state.segment(0, 3) = floatingBasePosition;
  state(3) = floatingBaseOrientation.x();
  state(4) = floatingBaseOrientation.y();
  state(5) = floatingBaseOrientation.z();
  state(state.rows() - 1) = floatingBaseOrientation.w();

  state.segment(6, jointStates.rows()) = jointStates;
}

inline void createGeneralizedVelocityVector(const Eigen::Vector3d &floatingBaseLinearVelocity, const Eigen::Vector3d &floatingBaseAngularVelocity,
                                            const Eigen::VectorXd &jointStatesVelocity, Eigen::VectorXd &state){

  if(state.rows() != jointStatesVelocity.rows() + 6){
    throw std::runtime_error("Missmatch between vectors creating generalized vector");
  }

  state.segment(0, 3) = floatingBaseLinearVelocity;
  state.segment(3, 3) = floatingBaseAngularVelocity;
  state.segment(6, jointStatesVelocity.rows()) = jointStatesVelocity;
}

inline void createGeneralizedAccelerationVector(const Eigen::Vector3d &floatingBaseLinearAcceleration, const Eigen::Vector3d &floatingBaseAngularAcceleration,
                                                const Eigen::VectorXd &jointStatesAcceleration, Eigen::VectorXd &state){

  if(state.rows() != jointStatesAcceleration.rows() + 6){
    throw std::runtime_error("Missmatch between vectors creating generalized vector");
  }

  state.segment(0, 3) = floatingBaseLinearAcceleration;
  state.segment(3, 3) = floatingBaseAngularAcceleration;
  state.segment(6, jointStatesAcceleration.rows()) = jointStatesAcceleration;
}




#endif
