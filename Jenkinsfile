pipeline {
    agent any
    stages {
        stage('Checkout Git')
        {
            steps {
                git branch: 'master', credentialsId: 'cc220cf9-31c8-4804-971b-dcb93036e30a', url: 'git@github.com:tchitchidead/push_swap.git'
            }
        }
        stage('Nettoyage') {
            steps {
               sh 'export TERM=xterm; make clean'
            }
        }  
        stage('build push_swap') {
            steps {
               sh 'export TERM=xterm; make push_swap'
            }
        }  
        stage('build checker') {
            steps {
                sh 'export TERM=xterm; make checker'
            }    
        }
        stage('Test OK') {
            steps {
                sh './push_swap 45 3 8 2 5 6 9 1 | ./checker 45 3 8 2 5 6 9 1'
            }
        }
            stage('Test KO') {
            steps {
                sh './push_swap 45 3 8 2 5 6 9 1 | ./checker 45 3 8 2 5 10 9 1'  
            }
        }
    }   
}
