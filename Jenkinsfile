pipeline {
    agent any
    tools {
        maven 'Latest'
    }
    stages {
        stage('Checkout')
        {
            steps {
                git branch: 'main', credentialsId: 'cc220cf9-31c8-4804-971b-dcb93036e30a', url: 'git@github.com:tchitchidead/hello_world.git'
            }
        }
        stage('Generate')
        {
            steps {
                sh 'mvn generate-test-resources process-test-resources'
            }
        }
        stage('Compile') {
            steps {
                sh 'mvn compile'
            }
        }
        stage('Test') {
            steps {
                sh 'mvn -Dmaven.test.failure.ignore=true -DtestFailureIgnore=true test'
            }
        }
        stage('Generate Jar') {
            steps {
                sh 'mvn -Dmaven.test.failure.ignore=true -DtestFailureIgnore=true package'
            }
        }
        stage('Process build') {
               parallel {
                    stage('Artifact Jar') {
                        steps {
                            archiveArtifacts artifacts: 'target/*.jar', followSymlinks: false
                        }
                    }
                    stage('Process Test reports') {
                        steps {
                            junit checksName: 'Jenkins Junit Tests', skipMarkingBuildUnstable: true, testResults: 'target/surefire-reports/*.xml'
                        }
                    }
               }
        }
    }
}
