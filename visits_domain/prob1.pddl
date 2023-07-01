(define (problem prob1)
(:domain localization)
(:objects

     R2D2 - robot


     r0 - region
     r1 - region
     r2  - region
     r3 - region
     r4 - region
     r5 - region
    
)
(:init
    (robot_in R2D2 r0)


    ; all of the corner regiosn are not visited 
     (not(visited r2))
     (not(visited r0))   (not(visited r3))
     (not(visited r1)) 
     
     ;the region 5 which represents the submission desk is not visited intially
     (not(visited r5)) 
  

    (= (set r1) 1)
    (= (set r2) 1) 
    (= (set r3) 1) 
    (= (set r4) 1)

      (= (act-cost) 0)
    (= (dummy) 0)

    

 )

(:goal 
     ; we assume the two assignments for the robot to take are in regions 2 and 3 since we are given the choice 
;the robot should then head to the desk after taking the assignments reports 
;the desk is refered as r5 (region goal)
     (and (robot_in R2D2 r5) 
     ; the robot should be positioned in region 5 which represents the submissino desk 
     (taken r2) (taken r3)
     ; assignment reports from regions 2 and 3 must be taken by the report 
      (visited r2) (visited r3))
     ; regions 2 and 3 must be visted by the robot 
     
     
)
     (:metric minimize (act-cost))
)

