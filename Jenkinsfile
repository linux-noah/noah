node {
    stage "Clone"
    git url: "/Users/nullpo/noah/", branch: "feature/testing_framework"
    sh "git clean -fx"

    stage "Build Noah"
    sh "make build/noah"

    stage "User Program Test"
    sh "make test"
}
