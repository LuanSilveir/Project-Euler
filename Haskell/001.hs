import Data.Time

main :: IO ()
main = do 
  startTime <- getCurrentTime
  let result = solution
  endTime <- getCurrentTime
  let diffTime = diffUTCTime endTime startTime
  putStrLn ("Solution: " ++ (show result))
  putStrLn ("Execution Time: " ++ (show diffTime))

solution :: Int 
solution = sum [x | x <- [1..999], x `mod` 3 == 0 || x `mod` 5 == 0]


