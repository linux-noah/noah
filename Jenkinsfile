node {
    stage "Clone Repository"
    checkout scm
    sh "git clean -fx"

    stage "Build Noah"
    sh "make libexec/noah"

    stage "User Program Test"
    sh "make test"
}
