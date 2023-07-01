(define (domain localization)

(:requirements :typing :durative-actions :numeric-fluents :negative-preconditions :action-costs :conditional-effects :equality :fluents
)

(:types robot region
)

(:predicates

        (taken ?r - region) (robot_in ?v - robot ?r - region)  (close_to ?r1 ?r2 - region) 
		;  regions close to each other
		(visited ?r - region )   
        ; taken - assignment taken by the robot
        ;(connected ?r1 ?r2 - region)	
		; connecting regions to each other 
		 (reachable ?r - region)
		 ;predicate for regions being reachable
)

(:functions 
        (set ?r - region)(act-cost) (triggered ?from ?to - region) 
		(dummy)
                
		
)

(:durative-action goto
		:parameters (?v - robot ?from ?to - region )
		:duration (= ?duration 100)
		:condition (and (at start (robot_in ?v ?from)))
	    :effect (and (at start (not (robot_in ?v ?from))) 
			         (at start (increase (triggered ?from ?to) 1))
		             (at end (robot_in ?v ?to)) 
					 (at end (assign (triggered ?from ?to) 0)) 
					 (at end (visited ?to)) 
                     (at end (increase (act-cost) (dummy))))
)

(:durative-action analyze
  :parameters (?v - robot ?r - region)
  :duration (= ?duration 200)
  :condition (and
    (at start (robot_in ?v ?r))
	; the robot is at set region 
    (at start (visited ?r))
	; the region is visited 
  )
  :effect (and
    (at end (increase (act-cost) 50))
    (at end (reachable ?r))
	; mark the region  as reachable
  )
)


;durative action take for the robot to take the assignment report 
(:durative-action take
	:parameters (?v - robot ?r - region)
	:duration (= ?duration 100)
	:condition (and 
	; robot is at region and robot did not take the assignment 
		(at start (robot_in ?v ?r))
	;in initial condition the valuer of region r should be different from 0 
		(at start (> (set ?r) 0))
		)
	:effect ( and
	; the assignment report is now taken byt the robot
		(at end (taken ?r))
		)
	)
	
)

