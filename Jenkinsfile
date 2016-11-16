node {
    stage "Clone Repository"
    checkout scm
    sh "git clean -fx"

    stage "Build Noah"
    sh "cmake ."
    sh "make"

    stage "User Program Test"
    sh "make test ARGS=-V"
}
