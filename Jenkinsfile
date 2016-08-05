node {
    stage "Clone"
    checkout scm
    sh "git clean -fx"

    stage "Build Noah"
    sh "make build/noah"

    stage "User Program Test"
    sh "make test"
}
