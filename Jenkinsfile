node {
    stage "Clone Repository"
    checkout scm
    sh "git clean -fx"

    stage "Build Noah"
    sh '''mkdir build
      cd build
      cmake ..
      make'''

    stage "User Program Test"
    sh '''cd build
      make test ARGS=-V'''
}
