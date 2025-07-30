import Data.Time

main :: IO ()
main = do 
  !startTime <- getCurrentTime
  let !result = solution
  !endTime <- getCurrentTime
  let diffTime = diffUTCTime endTime startTime
  putStrLn ("Solution: " ++ (show result))
  putStrLn ("Execution Time: " ++ (show diffTime))
  --putStrLn $ (reverse.tail.reverse) (show diffTime)

solution :: Int 
solution = head triplet

triplet :: [Int]
triplet = [a*b*c | a <- [1..998], b <-[1..998], let c = (1000-a-b), a^2 + b^2 == c^2]

