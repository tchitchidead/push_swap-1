pipeline {
    agent any
    tools {
        cmake 'Latest'
    }
    stages {
        stage('Checkout')
        {
            steps {
                git branch: 'master', credentialsId: 'cc220cf9-31c8-4804-971b-dcb93036e30a', url: 'git@github.com:tchitchidead/push_swap-1.git'
            }
        }
        stage('Compile') {
            steps {
                sh 'cmakeBuild buildDir: 'build', installation: 'Latest''
            }
        }
        stage('Test') {
            steps {
                sh 'ctest 'Latest''
            }
        }
        stage('Generate Jar') {
            steps {
                sh 'mvn -Dmaven.test.failure.ignore=true -DtestFailureIgnore=true package'
            }
        }
    }   
}
