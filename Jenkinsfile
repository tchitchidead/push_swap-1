pipeline {
    agent any
    //tools {
    //    cmake 'Latest'
    //}
    stages {
        stage('Checkout')
        {
            steps {
                git branch: 'master', credentialsId: 'cc220cf9-31c8-4804-971b-dcb93036e30a', url: 'git@github.com:tchitchidead/push_swap-1.git'
            }
        }
        stage('build push_swap') {
            steps {
               sh 'make -f push_swap'
            }
        }  
        stage('build checker') {
            steps {
                sh 'make -f checker'
            }    
        }
    }   
}
