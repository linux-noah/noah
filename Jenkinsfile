node {
  try {
    stage "Clone Repository"
    checkout scm
    sh "git clean -fx"

    stage "Build Noah"
    sh '''mkdir -p build
      cd build
      cmake ..
      make'''

    stage "User Program Test"
    sh '''cd build
      make test ARGS=-V'''
  } catch (e) {
    currentBuild.result = "FAILED"
    slackSend message: "FAILED: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]' (${env.BUILD_URL})"
    throw e
  }
}
