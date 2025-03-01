<?php
session_start();

$servername = "localhost";  
$username = "root";         
$password = "";             
$dbname = "macbeth_db";     

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$act = isset($_POST['act']) ? $_POST['act'] : null;
$scene = isset($_POST['scene']) ? $_POST['scene'] : null;
$analysis_text = "";

if ($act && $scene) {
    $act_value = "Act " . $act;
    $scene_value = "Scene " . $scene;

    $sql = "SELECT analysis_text FROM analyses WHERE act = ? AND scene = ?";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("ss", $act_value, $scene_value);  
    $stmt->execute();
    $result = $stmt->get_result();

    if ($result->num_rows > 0) {
        $row = $result->fetch_assoc();
        $analysis_text = $row['analysis_text'];
    } else {
        $analysis_text = "Analysis not available for the selected act and scene.";
    }

    $stmt->close();
}

$conn->close();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Analysis - Macbeth</title>
    <link rel="stylesheet" href="style.css"> 
    <style>
        .hidden {
            display: none;
        }
        .profile-icon {
            width: 40px;
            height: 40px;
            border-radius: 50%;
            cursor: pointer;
        }
        .profile-dropdown {
            position: absolute;
            top: 50px;
            right: 10px;
            background-color: white;
            border: 1px solid #ccc;
            box-shadow: 0 2px 5px rgba(0,0,0,0.2);
            display: none;
        }
        .profile-dropdown a {
            display: block;
            padding: 10px;
            text-decoration: none;
            color: black;
        }
        .profile-dropdown a:hover {
            background-color: #f0f0f0;
        }
    </style>
</head>
<body>
    <header>
        <nav>
            <ul class="navbar">
                <li><a href="index.php">Home</a></li>
                <li><a href="image-to-text.php">Image to Text Generator</a></li>
                <li class="dropdown">
                    <a href="macbeth-info.php" class="dropbtn">Macbeth</a>
                    <div class="dropdown-content">
                        <a href="summary-generator.php">Summary Generator</a>
                        <a href="flashcards-generator.php">Flashcards Generator</a>
                        <a href="questions-generator.php">Questions Generator</a>
                        <a href="analysis.php">Analysis</a>
                        <a href="poetic-devices.php">Poetic Devices</a>
                    </div>
                </li>
            </ul>     
        </nav>
    </header>

    <section id="content">
        <h1>Analysis</h1>

        
        <form method="POST" action="analysis.php">
            <div class="select-container">
                <select name="act" required>
                    <option value="" disabled selected>Select Act</option>
                    <option value="1" <?php echo isset($act) && $act == 1 ? 'selected' : ''; ?>>Act 1</option>
                    <option value="2" <?php echo isset($act) && $act == 2 ? 'selected' : ''; ?>>Act 2</option>
                    <option value="3" <?php echo isset($act) && $act == 3 ? 'selected' : ''; ?>>Act 3</option>
                    <option value="4" <?php echo isset($act) && $act == 4 ? 'selected' : ''; ?>>Act 4</option>
                    <option value="5" <?php echo isset($act) && $act == 5 ? 'selected' : ''; ?>>Act 5</option>
                </select>

                <select name="scene" required>
                    <option value="" disabled selected>Select Scene</option>
                    <option value="1" <?php echo isset($scene) && $scene == 1 ? 'selected' : ''; ?>>Scene 1</option>
                    <option value="2" <?php echo isset($scene) && $scene == 2 ? 'selected' : ''; ?>>Scene 2</option>
                    <option value="3" <?php echo isset($scene) && $scene == 3 ? 'selected' : ''; ?>>Scene 3</option>
                    <option value="4" <?php echo isset($scene) && $scene == 4 ? 'selected' : ''; ?>>Scene 4</option>
                    <option value="5" <?php echo isset($scene) && $scene == 5 ? 'selected' : ''; ?>>Scene 5</option>
                    <option value="6" <?php echo isset($scene) && $scene == 6 ? 'selected' : ''; ?>>Scene 6</option>
                    <option value="7" <?php echo isset($scene) && $scene == 7 ? 'selected' : ''; ?>>Scene 7</option>
                </select>

                <button type="submit">Show Analysis</button>
            </div>
        </form>

        <div id="contentDisplay">
            <?php if (!empty($analysis_text)) : ?>
                <p><?php echo $analysis_text; ?></p>
            <?php endif; ?>
        </div>
    </section>

    <script src="script.js"></script>
</body>
</html>
